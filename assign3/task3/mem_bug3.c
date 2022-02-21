#include <stdio.h>
#include <stdlib.h>
int * makearray(int size,int base){

  int i;
  int *j;

    j= calloc(size*2, sizeof(int));

  for(i=0;i<size;i++)
    j[i] = base*=2; //doubling base
  return j;
}

int main(){
  int * arr1 = makearray(5,2);
  int * arr2 = makearray(10,3);
  int j, res=0;

  for(j=0;j<5;j++){
    printf("%d ",arr1[j]);
    res+=arr1[j];
  }
  printf("\n");

  for(j=0;j<10;j++){
    printf("%d ",arr2[j]);
    res+= arr2[j];
  }
  printf("\n");
  printf("SUM: %d\n", res);
  free(arr1);
  free(arr2);
}

