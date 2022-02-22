#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	//TODO: your implementation
	char* bin = (char* )malloc(50);
  int bit = 0x80000000;
  int i=0,j;
  bin[0] = '0';
  bin[1] = 'b';
  bin[50] = '\0';
  for(j =0;j<32;j++) {
      if(j%4 == 0 && j > 0){
         bin[i++] = ' ';
        }
      if(dec & bit) {
        bin[i++] = '1';
        }
      else {
        bin[i++] = '0';
        dec <<= 1;
        }
  }
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
