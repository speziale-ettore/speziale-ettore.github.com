---
layout: page
title: Implementazione del Costrutto foreach
---
{% include JB/setup %}

A lezione abbiamo visto una implementazione parziale del costrutto ``foreach``.
Dove è possibile recuperare l'implementazione completa?

Il costrutto ``foreach`` visto in classe permette di visitare tutti gli elementi di un array:

    int els[10];

    foreach(el in els)
      write(el);

La patch completa è scaricabile [qui](/teaching/download/lfc/foreach.diff).
