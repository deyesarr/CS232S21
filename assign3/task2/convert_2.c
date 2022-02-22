#include<stdio.h>
#include<stdlib.h>
//Program to convert a 32-bit Decimal numbers to Binary
//1) Do not change the signature of convert_2, or your task receives zero
//2) No globals allowed.
char* convert_2(int dec)
{
	//TODO: your implementation
 int arr= 32;
    char *con;
    con = (char*)malloc((arr+9)*sizeof(char)); 
    con[0] = '0';
    con[1] = 'b';
    int located = arr + 8; //(arr+9)-1
    int i = 1;

    while(located >= 2)
    {
        if(i == 0 ) { 
                con[located] = ' ';
                }
                else {
                if(dec&1) {  
                                b[located] ='1';
                        }
                        else {
                                b[located] ='0';
                        }
                dec >>= 1;        
                } 
            located--; 
            i = (i+1)%5; 
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
    free(bin);
}
