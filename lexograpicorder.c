
#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
  char a[100];
  scanf("%[^\n]s",a);
  int i,c=0,n,b[10],x=0;
  
  n=strlen(a);
  
  for(int i=0;i<n;i++)
  {
      if(a[i]==' ')
      {
          i++;
          c=0;
          x++;
      }
      if(a[i]<a[i+1])
      {
          c++;
          b[x]=c;
      }
  }
  int res=0,l=0;
  for(int i=x;i>=0;i--)
  {
      res=res+pow(10,l++)*b[i];
  }
  printf("%d",res);
}
