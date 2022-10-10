#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
void towers(int,char,char,char);
int i,j,top=-1;
char symbol,postfix[50];
float s[40];
float value[20];
float op1,op2,res;

float compute()
{
    switch(symbol){
        case '+': return op1+op2;
        case '-': return op1-op2;
        case '*': return op1*op2;
        case '%': return((int)op1%(int)op2);
        case '/': if(op2==0)
        {
        printf("divide by zero error!\n");
        exit(0);
        }
        else
        return op1/op2;
        case '^': return pow(op1,op2);
    }
}
void main()
{
    int n,c;
    while(1){
        i=0;
        printf("\n1.suffix\n");
        printf("2.hanoi tower\n");
        printf("3.exit\n");
        printf("your choice\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:printf("enter the suffix expresssion\n");
        scanf("%s",postfix);
        top=-1;
        while(postfix[i]!='\0')
        {
            if(isalpha(postfix[i]))
            {
                printf("enter the values for %c\n",postfix[i]);
                scanf("%f",&value[i]);
            }
            i++;
        }
        for(i=0;i<strlen(postfix);i++)
        {
            symbol=postfix[i];
            if(isalpha(postfix[i]))
            {
               s[++top]=value[i];
            }
            else{
                op2=s[top--];
                op1=s[top--];
                res=compute();
                s[++top]=res;
            }
        }
        printf("the value after solving posfix %f",res);
        break;
        case 2:printf("enter the no of disks\n");
        scanf("%d",&n);
        printf("sequence of move involved are\n");
        towers(n,'A','C','B');
        break;
        case 3: return;
        default:printf("invalid choice");


        }
    }
}
void towers(int n,char frompeg ,char topeg,char auxpeg)
{
    if(n==1)
    {
        printf("move disk 1 from peg %c to to peg %c\n",frompeg,topeg);
        return;
    }
    towers(n-1,frompeg,auxpeg,topeg);
    printf("move disk %d from peg %c to to peg %c\n",n,frompeg,topeg );
    towers(n-1,auxpeg,topeg,frompeg);
}