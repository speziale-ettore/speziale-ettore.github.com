---
layout: page
title: Linguaggi Formali e Compilatori
---
{% include JB/setup %}

Il corso è erogato agli studenti del quarto anno di Ingegneria Informatica.
Gli argoment trattati riguardanono principalmente le tecniche di parsing necessarie per implementare il front-end di un compilatore.
Il docente del corso è il Professor [Stefano Crespi Reghizzi](mailto:crespi@elet.polimi.it).
Io mi occupo di mostrare agli studenti come gli aspetti teorici mostrati a lezioni vengono utilizzati all'interno di un semplice compilatore didattico.
In particolare, durante le esercizationi viene mostrato l'utilizzo di [Flex][www/flex] e [Bison][www/bison] per automatizzare la costruzione del parser e del lexer del compilatore ACSE.
Flex e Bison sono gia disponibili pacchettizzati all'interno di tutte le distribuzioni Linux, mentre ACSE è scaricabile dal sito del corso sulla piattaforma [Corsi On Line][www/corsiOnLine].

Si ricorda agli studenti che il corso prevede un esame suddiviso in due parti: una parte teorica e una parte pratica nella quale è richiesto di aggiungere semplici costrutti al compilatore oggetto delle esercitazioni.

Anno Accademico 2010-2011
-------------------------
Quest'anno il corso prevede 5 esercitazioni di laboratorio.
In realtà non è un vero e proprio laboratorio perchè le lezioni non si svolgono in laboratorio ma in classe.
Di seguito sono disponibili le slide utilizzate:

* [Introducing Formal Languages and Compilers Laboratory](/teaching/download/lfc/2010-2011/introducing-formal-languages-and-compilers-laboratory.pdf)
* [Lexical Analysis](/teaching/download/lfc/2010-2011/lexical-analysis.pdf)
* [Semantic Analysis](/teaching/download/lfc/2010-2011/semantic-analysis.pdf)
* [Introducing ACSE](/teaching/download/lfc/2010-2011/introducing-acse.pdf)
* [Linear ACSE](/teaching/download/lfc/2010-2011/linear-acse.pdf)
* [Control in ACSE](/teaching/download/lfc/2010-2011/control-in-acse.pdf)

Gli esempi mostrati sulle slides sono, per ragioni di spazio, banali.
Siete perció pregati di consultare il codice di ACSE, che costituisce la migliore documentazione disponibile.

Quest'anno il tutorato di linguaggi per la preparazione dell'esame di cui sono responsabile è tenuto Lunedi 28 Febbraio 2011, in sala conferenze presso il Dipartimento di Elettronica ed Informazione.
Come al solito, la lezione mattutina (09:15 - 12:15) tratta gli argormenti teorici, mentre la lezione pomeridiana (14:15 -- 17:15) è focalizzata sulla preparazione della prova di laboratorio:

* [Tutorato Linguaggi Formali e Compilatori](/teaching/download/lfc/2010-2011/tutorato-linguaggi-formali-e-compilatori.pdf)

Durante il tutorato, assieme agli studenti, è stata sviluppata una patch per supportare il costrutto `switch` in ACSE.
Sia la semantica che la sintassi del costrutto sono basate su quelle specificate dal linguaggio C, con le seguenti limitazioni:

* c'è sempre almeno un case
* c'è sempre il blocco default
* gli switch non possono essere innestati
* la keyword `break` può comparire ovunque

La patch è disponibile [qui](/teaching/download/lfc/2010-2011/switch.diff).

---

Archivio Esami
--------------
Durante il corso ho collaborato con altri esercitatori nella preparazione dei temi d'esame.
La procedura standard da noi seguita è che il testo di ogni appello è preparato assieme, mentre la scrittura effettiva della soluzione è assegnata ad un solo esercitatore.
Per un archivio completo delle soluzioni si veda il sito del corso, mentre di seguito sono disponibili le soluzioni fatte da me:

* [Appello 02/09/2010](/teaching/download/lfc/2009-2010/intrinsic-vettoriali.pdf):
  [vectorial-intrinsics.diff](/teaching/download/lfc/2009-2010/vectorial-intrinsics.diff)
* [Appello 04/03/2011](/teaching/download/lfc/2010-2011/eccezioni.pdf):
  [exceptions.diff](/teaching/download/lfc/2010-2011/exceptions.diff)
* [Appello 20/06/2011](/teaching/download/lfc/2010-2011/operatori-esoterici.pdf):
  [esoteric-operators.diff](/teaching/download/lfc/2010-2011/esoteric-operators.diff)
* [Appello 08/09/2011](/teaching/download/lfc/2010-2011/shift-rotate.pdf):
  [shift-rotate.diff](/teaching/download/lfc/2010-2011/shift-rotate.diff)

La soluzione dell'esame per la parte relativa alla modifiche da apportare ad ACSE è fornita sotto forma di patch.
Nel caso non sapeste applicare una patch, alla fine del testo di ogni soluzione è disponibile una breve guida.

---

ACSE Questions
--------------
In questa sezione troverete delle risposte ad alcune domande che mi vengono poste dagli studenti circa il compilatore ACSE.
Preferisco rispondere qui, piuttosto che per mail.
In questo modo la risposta può essere utile anche ad altre persone:

* [Inizializzazione delle Variabili](/teaching/questions/lfc/inizializzazione-delle-variabili.html)
* [Implementazione del Costrutto foreach](/teaching/questions/lfc/implementazione-del-costrutto-foreach.html)
* [Implementazione dei Puntatori](/teaching/questions/lfc/implementazione-dei-puntatori.html)

All'interno di ogni pagina troverete la domanda cosi come posta dallo studente e la relativa risposta.

---

Cheat Sheet
-----------
Gli header file di ACSE sono pesantemente commentati.
Stamparseli può essere utile per consultare velocemente i sorgenti.

* [ACSE Quick Reference](/teaching/download/lfc/acse-quick-reference.pdf)

È caldamente consigliato _stampare il cheat sheet_ e _portarlo all'esame_.

[www/flex]: http://flex.sourceforge.net
[www/bison]: http://www.gnu.org/software/bison
[www/corsiOnLine]: http://corsi.metid.polimi.it
