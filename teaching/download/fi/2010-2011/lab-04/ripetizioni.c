
#include <stdio.h>

#define MAX 20

int main(int argc, char* argv[]) {
  int nums[MAX]; 
  int rep; 
  int i, j;

  printf("Inserisci %d numeri: ", MAX); 
  for( i = 0; i < MAX; i++){
    scanf("%d", &nums[i]);
  }

  printf("Numeri: ");
  for(i = 0; i < MAX; i++){
    for(j = i - 1,rep = 0; j >= 0 && rep == 0; j--)
      if(nums[i] == nums[j])
        rep = 1;
      if(rep != 1)
        printf("%d ", nums[i]);
  }
  printf("\n");

  return 0;
} 
