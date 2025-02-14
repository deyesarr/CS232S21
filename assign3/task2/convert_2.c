#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	//TODO: your implementation
	char* con = (char* )malloc(50);
  int bit= 0x80000000;
  int i=0,j;
  con[i++] = '0';
  con[i++] = 'b';
  //loop 32 times
  for(j=0;j<32;j++) {
      //spaces between
      if(j%4 == 0 && j > 0) con[i++] = ' ';
      if(dec & bit) con[i++] = '1';
      else con[i++] = '0';
      // left bit shift
      dec <<= 1;
  }
  return con;
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