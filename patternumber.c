#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number :");
    scanf("%d", &n);
    int Patternlen = (n * 2) - 1;
    for (int i = 0; i < Patternlen; i++)
    {
        for (int j = 0; j <Patternlen; j++)
        {
            int min = i < j ? i : j;
            min = min < Patternlen - i ? min : Patternlen - i - 1;
            min = min < Patternlen - j - 1 ? min : Patternlen - j - 1;
            printf("%d ", n - min);
        }
        printf("\n");
    }
    return 0;
}
