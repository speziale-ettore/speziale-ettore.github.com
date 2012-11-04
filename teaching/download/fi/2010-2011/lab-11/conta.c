
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define PROCS 10
#define RANGE 20

int main (int argc, char *argv[]) {
  pid_t pid;
  int i, j, status;
  
  for(i = 0; i < PROCS; i++) {
    pid = fork();
    if(pid == 0) {
      printf("Figlio %d conta: ", (int) getpid());
      for(j = 0; j < RANGE; j++)
        printf("%d ", i * RANGE + j + 1);
      printf("\n");
      return 0;

    } else {
      pid = wait(&status);
      if(WIFEXITED(status)) {
        printf("Figlio %d terminato: %d\n", (int) pid, status);
      } else {
        printf("Figlio terminato in modo anomalo: %d\n", status);
      }
    }
  }

  return 0;
}
