/*memleak_example.c*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

  int * a = malloc(sizeof(int *));

  *a = 10;  

  printf("%d\n", *a);
  free(a);
  
  a = malloc(sizeof(int *)*3);
  a[0] = 10;
  a[1] = 20;
  a[2] = 30;

  printf("%d %d %d\n", a[0], a[1], a[2]);
  free(a);
}

// -The memory for the first malloc pointer is never freed; The second malloc statement rewrites and erases the value of the first malloc pointer and causes a leak.
  //- leak fix: free memory after each print statement