---
layout: page
title: Implementatzione dei Puntatori
---
{% include JB/setup %}

Ho provato ad implementare gli operatori ``*`` e ``&`` in in questo modo:

    exp: ...
    MUL_OP IDENTIFIER {
      t_axe_register val = getNewRegister(program);
      t_axe_label id_label = getLabelFromVariableID(program, $2);

    gen_load_instruction(program, val, id_label, 0);
    $$.value = val;
    } |
    AND_OP IDENTIFIER {
      t_axe_register val = getNewRegister(program);
      t_axe_label id_label = getLabelFromVariableID(program, $2);
      gen_mova_instruction(program, val, id_label, 0);
      $$.value = val;
    }

La soluzione proposta è corretta?

Ni. La soluzione proposta contiene un grosso errore e delle inesattezze.

Per prima cosa analizziamo l'implementazione dell'operatore ``&``.
Essa è giusta, infatti viene generata una ``MOVA`` per caricare l'indirizzo di una cella di memoria in un registro.
Contiene un paio di inesattezze:

* la regola genera delle ambiguità.
  Infatti, come deve essere interpretata l'espressione ``4 & a``?
  Sappiamo che essa è un and bit-a-bit, ma il parser potrebbe riconoscerla anche come un costante seguita dall'operatore ``&``.

  Il problema nasce dal fatto che il simbolo ``&`` è utilizzato anche per descrivere due operatori diversi.
  Per ovviare al problema, bisogna forzare la precedenza della regola:

      %token ANDAND OROR
      %token ADDR_OP
      ...

      %right NOT_OP ADDR_OP
      ...
      AND_OP IDENTIFIER
      %prec ADDR_OP { ... }

  In questo modo la regola assume la precedenza del token ``ADDR_op``, un token fasullo che serve solo per dettare la precedenza della regola

* con l'istruzione ``$$.value = val;`` si vuole scrivere nella variabile ``$$``.
  Tale variabile, però, contiene anche altri campi che non vengono inizializzati.
  Il modo corretto di create una nuova espressione è utilizzare la funzione ``create_expression``:

      $$ = create_expression(val, REGISTER);

  In questo modo tutti i campi vengono inizializzati correttamente

Questi due errori sono stati commessi anche nell'implementazione dell'operatore ``*``.

L'errore grosso è contenuto all'interno dell'implementazione dell'operatore ``*``.
Esso permette di effettuare un accesso indiretto alla memoria, mentre nella soluzione proposta si va ad effettuare un accesso diretto.
Ne consegue che l'espressione ``*a`` invece di ritornare il valore contenuto nella cella di memoria puntata da ``a``, ritorna il valore contenuto nella cella di memoria contente ``a``, cioè il contenuto di ``a``.

Il modo più semplice per implementare l'operatore ``*`` è generare una ``LOAD`` che sia a conoscenza del fatto che l'indirizzo da caricare deve essere utilizzato per un accesso indiretto.
Tale operazione non è implementata in ACSE, tuttavia tutte le operazioni ternarie hanno la possibilità di avere il registro destinazione e/o il secondo registro sorgente indirizzato indirettamente, perciò si può "simulare" la load indiretta con una ``ADD``:

      int id_reg = get_symbol_location(program, $2, 0);
      gen_add_instruction(program,
                          dest_reg,
                          REG_0,
                          id_reg,
                          CG_INDIRECT_SOURCE);

Il parametro flags viene settato a ``CG_INDIRECT_SOURCE`` per forzare ad indirizzare indirettamente il secondo parametro sorgente.
Il valore di tale parametro, il registro nella quale è contenuta ``a`` in questo caso, viene utilizzato come indirizzo per effettuare una ``LOAD`` dalla memoria.
Siccome non si vuole modificare in alcun modo tale valore, il primo parametro della ``ADD`` è il registro ``R0``.

La patch per ACSE è disponibile [qui](/teaching/download/lfc/pointers.diff).
