#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        scanf("%d", arr + i);
    }
    int t;
    for (i = 0; i < num / 2; i++)
    {
        t = *(arr + i);
        *(arr + i) = *(arr + num - i - 1);
        *(arr + num - i - 1) = t;
    }
    for (i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}