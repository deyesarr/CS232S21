#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int i, *a;

  a = malloc(sizeof(int)*11);

  for(i=0;i <= 10; i++){
    a[i] = i;
  }
  for(i=0;i <= 10; i++){
    printf("%d\n", a[i]);
  }
  free(a);
}

//Memory Leak Cause: Exceeding the bounds of the array. Leak Fix: Increasing size of array to account for leak & freeing memory of a.