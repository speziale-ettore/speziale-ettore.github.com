
#include <stdio.h>
#include <stdlib.h>

// definizione della struttura per la lista concatenata
typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// prototipi delle funzioni
elem* inserisci(elem*, int);
void visualizza(elem*);
elem* distruggiLista(elem*);

// inserisce un nuovo numero nella lista
elem* inserisci(elem* lista, int num) {
  elem *prec, *tmp;

  prec = lista;

  // raggiungi il termine della lista
  if (prec!=NULL) {
    while(prec->next != NULL) {
      prec = prec->next;
    }
  }

  tmp = (elem*) malloc(sizeof(elem));
  if(tmp != NULL) {
    tmp->next = NULL;
    tmp->num = num;
    if(lista == NULL)
      lista = tmp;
    else
      prec->next = tmp;
  } else
      printf("Memoria esaurita!\n");

  return lista;
}

// visualizza i numeri contenuti nella lista
void visualizza(elem* lista) {
  printf("Elementi nella lista: ");

  while(lista != NULL) {
    printf("%d ", lista->num);
    lista = lista->next;
  }

  printf("\n");  
}

// libera la memoria allocata per una lista
elem* distruggiLista(elem* lista) {
  elem* tmp;

  while(lista != NULL) {
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }

  return NULL;
}


int main(int argc, char* argv[]) {
  int scelta, num;
  elem* lista = NULL;

  printf("Inserire un numero naturale da aggiungere alla lista "
         "(Inserire un numero negativo per terminare): ");
  scanf("%d", &num);
  while(num >= 0) {
    lista = inserisci(lista, num);
    
    printf("Inserire un numero naturale da aggiungere alla lista "
           "(Inserire un numero negativo per terminare): ");
    scanf("%d", &num);
  }

  visualizza(lista);

  lista = distruggiLista(lista);

  return 0;
}
