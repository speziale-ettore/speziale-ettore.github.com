---
layout: page
title: Inizializzazione delle Variabili
---
{% include JB/setup %}

All'interno del file _axe\_utils.c_ tra le righe 98-101, il commento sembra indicare che si procede ad emettere una istruzione di ``LOAD`` per una variabile scalare:

    /* add a load instruction for each declared variable
     *  that is not an array type */
     if (!(current_decl->isArray))
        get_symbol_location(program, current_decl->ID, 0);

La funzione ``get_symbol_location()``, fra le altre cose, dovrebbe generare un'istruzione di ``LOAD`` per la variabile, mentre per come viene invocata (l'ultimo parametro passato -- ``genLoad`` --, è uno 0) non lo fa.
Visto che l'istruzione di ``LOAD`` è indispensabile non capisco come le cose possano funzionare.

Ad esempio:

    int a = 2;
    write(a);

Come viene gestita la ``LOAD`` in questo caso?

Analizzando la dichiarazione della variabile ``a`` il compilatore ACSE compie due azioni:

* aggiunge alla lista delle variabili dichiarate ``a``
* crea un registro temporaneo per contenere la variabile ``a``

Entrambe le azioni vengono svolte nella funzione ``set_new_variables``.

In un primo momento -- _axe-utils.c_:69-84 -- si scorre la lista di tutte le variabili dichiarate e si crea la struttura per rappresentarle.
La funzione ``createVariable`` serve a questo.
I parametri notevoli che le vengono passati sono due:

* il nome della variabile: ``current_decl->ID``
* il valore di inizializzazione: ``current_decl->init_val``

Tramite ``createVariable`` ACSE registra tale informazioni nella symbol table.
Per ora non fa null'altro a livello di generazione del codice, ma queste informazioni gli serviranno in seguito.

Dopo una prima scansione della lista delle variabili se ne fa un'altra -- _axe-utils.c_:90-108 -- nella quale si crea un registro temporaneo per allocare le variabili scalari.
Tale azione viene eseguita dalla funzione ``get_symbol_location``.

Il commento in _axe-utils.c_:98-99 è un errore di scrittura: non viene generata nessuna ``LOAD``.
Alla fine della funzione ``set_new_variables`` il compilatore ha segnato in una sua struttura dati interna tutte le variabili dichiarate, e nel caso di variabili scalari ha anche allocato un registro temporaneo per contenerle.
Non ha emesso alcuna istruzione!

Successivamente viene riconosciuta l'istruzione ``write`` e viene generato il codice per stampare il contenuto di ``a``.
A questo punto il codice generato è:

    WRITE R1 0

Dove ``R1`` è il registro temporaneo destinato a contenere ``a``.
La ``LOAD`` non è ancora stata generata

Proseguendo con l'analisi del programma, ad un certo punto si consuma tutto l'input e il parser termina: la funzione ``yyparse`` ritorna al chiamante, nel nostro caso il main -- _Acse.y_:582.

Per completare la traduzione il compilatore deve eseguire alcune operazione finali.
Una di queste è generare il codice per l'inizializzazione delle variabili.
Esso viene emesso all'interno della funzione ``updateProgramInfos``, richiamata in _Acse.y_:643.
A questo punto il codice generato è completo, e quindi abbiamo:

    LOAD R1 L0
    WRITE R1 0
    STORE R1 L0
    HALT

La ``LOAD`` è comparsa solo ora.
Essa è stata generata consultando le informazioni che ACSE aveva raccolto all'interno della funzione ``set_new_variables``.

Queste ``LOAD`` sono particolari e quindi è stata necessario gestirle separatamente all'interno del compilatore.
Per quanto riguarda il corso non ci sono problemi, basta sapere che esistono.
