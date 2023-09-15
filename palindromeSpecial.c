
#include <stdio.h>
#include <math.h>
#include <string.h>
int ReverseNumber();
int main ()
{
 int n;  
 scanf("%d",&n);
 n=n+rev(n);
 while(!ispalindrome(n))
 {
    n=n+rev(n);
 }
 printf("%d",n);
}

int rev(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n=n/10;
    }
    return r;
}

int ispalindrome(int n)
{
    int o=rev(n);
    return o==n;
}
