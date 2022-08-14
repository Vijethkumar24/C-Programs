#include<stdio.h>
#include<stdlib.h>
int a[10],i,n,p,ele;
void create()
{
    printf("enter the size of the array\n");
    scanf("%d",&n);
    printf("enter the array elemts\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
   

}
void display(){
    printf("the array elements are\n");
    for(i=0;i<n;i++)
    printf("%d at %d\t\n",a[i],i);
}
     
void  insert(){
    printf("eneter the valid pos where u wish to insert\n");
    scanf("%d",&p);
    printf("enter the element that needes to be inserted\n");
    scanf("%d",&ele);
    if(p>=n+1){
        printf("invalid pos\n");

    }
    else{
        for(i=n-1;i>=p;i--)
        a[i+1]=a[i];
        a[p]=ele;
    }
}
void delete()
{
     printf("eneter the valid pos where u wish to delete:\n");
    scanf("%d",&p);
    if(p>=n+1){
        printf("invalid pos\n");

    }
    else{
        for(i=p;i<=n-1;i++
        )
             a[i]=a[i+1];
       
    }
}
int main()
{
    int ch;
    while(1){
        printf("\n1.create\n");
        printf("2.display\n");
        printf("3.insert\n");
        printf("4.delete\n");
        printf("5.exit\n");
        printf("choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: create();
            break;
        case 2: display();
            break;
        case 3: insert();
            break;
        case 4: delete();
            break;
        case 5: return 0;
        default:
        printf("invalid choice\n");
        break;
        }
        

    }
}