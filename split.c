/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    // Write your logic to print the tokens of the sentence here.
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ')
        {
            printf("%c", s[i]);
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}