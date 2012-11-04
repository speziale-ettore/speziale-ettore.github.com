
#include <stdio.h>
#include <stdlib.h>

// definizione della struttura per la lista concatenata
typedef struct elem_ {
  int num;
  struct elem_ *next;
} elem;

// prototipi delle funzioni
void mostraMenu(void);
elem* inserisci(elem*, int);
elem* cancella(elem*, int);
void visualizza(elem*);
int cerca(elem*, int);
int dimensione(elem*);
elem* riempiBuchi(elem*);
elem* rimuoviPari(elem*);
elem* rimuoviDispari(elem*);
elem* cancellaLista(elem*);

// visualizza il menu del programma
void mostraMenu() {
  printf("\nMenu:\n");
  printf("1) inserisci un nuovo numero\n");
  printf("2) cancella un numero\n");
  printf("3) cerca un numero\n");
  printf("4) visualizza la dimensione della lista\n");
  printf("5) riempi i buchi nella numerazione\n");
  printf("6) cancella i numeri pari\n");
  printf("7) cancella i numeri dispari\n");
  printf("8) esci\n");
  printf("Scegli un comando: ");
}

// inserisce un nuovo numero nella lista
elem* inserisci(elem* lista, int num) {
  elem *prec, *curr, *tmp;
  
  prec = NULL;
  curr = lista; 

  // ricerca della posizione dove inserire il numero
  while(curr != NULL && curr->num < num) {
    prec = curr;
    curr = curr->next;
  }

  // il numero va inserito se non presente nella lista
  if(!(curr != NULL && curr->num == num)) {
    tmp = (elem*) malloc(sizeof(elem));
    if(tmp != NULL){
      tmp->next = curr;
      tmp->num = num;
      if(prec == NULL)
        lista = tmp;
      else
        prec->next = tmp;
    } else
      printf("Memoria esaurita!\n");
  }

  return lista;
}

// cancella un numero dalla lista
elem* cancella(elem* lista, int num) {
  elem *prec, *curr, *tmp;
  prec = NULL;
  curr = lista; 

  // scorri la lista fino alla posizione dove si potrebbe trovare il numero
  while(curr != NULL && curr->num < num) {
    prec = curr;
    curr = curr->next;
  }

  // il numero viene cancellato se presente
  if(curr != NULL && curr->num == num) {
    tmp = curr;
    if(prec != NULL) 
      prec->next = curr->next;
    else
      lista = curr->next;
    free(tmp);
  }

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

// verifica se un numero è presente nella lista
int cerca(elem* lista, int num) {
  int found = 0;
  int end = 0;

  while(lista != NULL && !end) {
    if(lista->num >= num) {
      end = 1;
      if(lista->num == num)
        found = 1;
    }
    lista = lista->next;
  }

  return found;
}

// calcola la dimensione della lista
int dimensione(elem* lista) {
  int dim = 0;

  while(lista != NULL)
    dim++;

  return dim;
}

// riempie i buchi nella numerazione dal primo all'ultimo numero
elem* riempiBuchi(elem* lista) {
  elem *prec, *curr, *tmp;  
  int min, max, i;
   
  if(lista != NULL) {
    // analizza il primo e l'ultimo numero nella sequenza
    min = lista->num;
    tmp = lista;
    while(tmp->next != NULL)
      tmp = tmp->next;
    max = tmp->num;

    // verifica se ciascun numero tra il primo e l'ultimo è presente nella
    // lista se assente, il numero viene aggiunto
    for(i = min; i < max; i++){
      if(!cerca(lista, i))
        lista = inserisci(lista, i);
    }
  }

  return lista;
}

// cancella numeri pari
elem* cancellaPari(elem* lista){
  elem *prec, *curr, *tmp;

  prec = NULL;
  curr = lista; 

  while(curr != NULL) {
    //se il numero corrente è pari, il numero viene cancellato
    if(curr->num % 2 == 0) {
      tmp = curr;
      if(prec != NULL) 
        prec->next = curr->next;
      else
        lista = curr->next;
      curr = curr->next;    
      free(tmp);    

    } else {
      prec = curr;
      curr = curr->next;    
    }
  }

  return lista;
}

// cancella numeri dispari
elem* cancellaDispari(elem* lista) {
  elem *prec, *curr, *tmp;

  prec = NULL;
  curr = lista;

  while(curr != NULL) {
    //se il numero corrente è dispari viene cancellato
    if(curr->num % 2 == 1) {
      tmp = curr;

      if(prec != NULL)
        prec->next = curr->next;
      else
        lista = curr->next;

      curr = curr->next;    
      free(tmp);    

    } else {
      prec = curr;
      curr = curr->next;    
    }
  }

  return lista;
}

// elimina tutti gli elementi contenuti nella lista
elem* cancellaLista(elem* lista) {
  elem *tmp;
  while(lista != NULL) {
    tmp = lista;
    lista = lista->next;
    free(tmp);
  }

  return lista;
}

int main(int argc, char* argv[]) {
  int scelta, num;
  elem* lista = NULL;

  do{
    visualizza(lista);
    mostraMenu();
    scanf("%d", &scelta);
    printf("\n");
    switch(scelta){
    case 1:
      printf("Numero da inserire: ");
      scanf("%d", &num);
      lista = inserisci(lista, num);
      break;
    case 2:
      printf("Numero da cancellare: ");
      scanf("%d", &num);
      lista = cancella(lista, num);
      break;
    case 3:
      printf("Numero da cercare: ");
      scanf("%d", &num);
      if(cerca(lista, num))
        printf("Numero trovato\n");
      else
        printf("Numero non trovato\n");
      break;
    case 4:
      printf("Dimensione della lista: %d\n", dimensione(lista));
      break;
    case 5:
      lista = riempiBuchi(lista);
      break;
    case 6:
      lista = cancellaPari(lista);
      break;
    case 7:
      lista = cancellaDispari(lista);
      break;
    case 8:
      printf("Fine\n");
      break;
    default:
      printf("Comando non valido!\n\n");
    }
  } while (scelta != 8);

  lista = cancellaLista(lista);

  return 0;
}

