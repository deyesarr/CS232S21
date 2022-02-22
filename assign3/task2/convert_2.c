#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	//TODO: your implementation
char* bin = (char*) malloc(50 * sizeof(char));
    int i = 49;
    if(dec & 0x80000000) {
        dec = -1 * dec;
        while(i >= 0) {
            if(i % 5 == 0) {
                bin[i--] = ' ';
            }
            bin[i--] = '0' + !(dec%2);
            dec = dec / 2;
        }
        bin[49] = '1';
    }
    else {  
        while(i >= 0) {
            if(i % 5 == 0) {
                bin[i--] = ' ';
            }
            bin[i--] = '0' + (dec%2);
            dec = dec / 2;
        }
    }
    bin[50] = '\0';
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
