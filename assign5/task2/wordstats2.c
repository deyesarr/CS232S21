#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {
    char buf[MAX_BUF];
    int n = 0, x = 0, character, exceed=strlen(buf)-1;;
      int countUpper = 0, countLower = 0, countChar = 0, countWord = 0, countLine = 0, countSpaces = 0, countNum = 0;

  printf("Enter input");
    while ((character = getchar()) != EOF && n < 1000)//while file still has chars
    {
        buf[n] = character;
        ++n;
    }
    if(exceed>=MAX_BUF)
    {
            printf("Allowed Characters Exceeded\n");
            return 0;
    }

    // Iteration conditions
    for (n = 0; buf[n]; n++)
    {
        if (buf[x] >= 'A' && buf[x] <= 'Z')// uppercase
        {
            countUpper++;
            countChar++;
        }
        if (buf[x] >= 33 && buf[x] <= 47)//special character
        {
            countChar++;    
        }
        else if (buf[x] >= 'a' && buf[x] <= 'z')//lowercase
        {
            countLower++;
            countChar++;
        }
        else if (buf[x] >= '0' && buf[x] <= '9')//number
        {
            countNum++;
            countChar++;
        }
        else if (buf[x] == 32)//space
        {
            countSpaces++;
            countWord++;
            countChar++;
        }
        else if (buf[x] == 10)//newline
        {
            countLine++;
            countWord++;
            countChar++;
        }
        x++;
    }
  
    printf("%d %d %d %d %d %d %d\n", countChar, countWord, countLine, countSpaces, countUpper, countLower, countNum);//print in numeric format
}

