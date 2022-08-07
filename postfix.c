#include<stdio.h>
#include<string.h>
int F(char Symbol)
{
    switch (Symbol)
    {
  
    
    case '+':
    case '-':return 2;
    case '%':
    case '*':
    case '/':return 4;
    case '^':
    case '$':return 5;
    case '(':return 0;
    case '#':return -1;
    default :return 8;
    }
}
int G(char Symbol)
{
    switch (Symbol)
    {

    case '+':
    case '-':return 1;
    case '%':
    case '*':
    case '/':return 3;
    case '^':
    case '$':return 6 ;
    case ')':return 0;
    case '(':return 9;
    default :return 7;

      }
}
void infix_postfix(char in[] ,char po[])
{
    int i,j=0;
    int top=-1;
    
    char s[40],Symbol;
    s[++top]='#';
    for(i=0;i<strlen(in);i++)
    {
        Symbol=in[i];
        while(F(s[top])>G(Symbol))
        {
            po[j]=s[top--];
            j++;
        }
        if(F(s[top])!=G(Symbol))
        {
            s[++top]=Symbol;
        }
        else{
            top--;
        }
        while(s[top]!='#')
        {
            po[j+1]=s[top--];
        }
        po[j]='\0';
    }
}
void main(){
    int i,c=0;
    char infix[40],postfix[40];
    printf("enetr the postfix expression\n");
    scanf("%s",infix);
    for(i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
        c++;
        if(infix[i]=='(')
        c--;
    }
    if(c==0)
    {
        infix_postfix(infix,postfix);
        printf("postfix for an infix expression is\n");
        printf("%s\n",postfix);

    }
    else{
        printf("invalid expression");
    }
}