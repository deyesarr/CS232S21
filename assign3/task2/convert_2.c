#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	//TODO: your implementation
int i, con, init;
  char *bin;
  init = 0;
  bin = (char*)malloc(32+1);

  for (i = 31; i >= 0; i--){
    con = dec >> i;
    if (con & 1)
      *(bin + init) = 1 + '0';
    else
      *(bin + init) = 0 + '0';
    init++;
  }
  *(bin + init) = '/0';
  return bin;
}

int main() {
	int n;
	char * bin;
	printf("Enter the Decimal Number\n");
	scanf("%d",&n);
	bin = convert_2(n);
	printf("The Binary Notation of %d is\t %s\n", n, bin);
	//TODO: do we need to release the memory of bin?
  free (bin);
}
