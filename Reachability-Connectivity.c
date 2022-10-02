#include<stdio.h>
#include<stdlib.h>
int a[20][20],s[20],i,n,v,reach[10],visited[20],j,top=-1;
int count=0;
void Reachability( int v)
{
    for(i=1;i<=n;i++)
    if(a[v][i]&&!visited[i])
        s[++top]=i;
    if(top>=0)
    {
        visited[s[top]]=1;
        Reachability(s[top--]);
    }
}
void Connectivity(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]&&!reach[i])
        {
         printf("%d->%d\n",v,i);
            count++;
            Connectivity(i);
        }
    }
}
void main()
{
    int v,choice;
    printf("Enter the number of cities\n");
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        s[i]=0;
        visited[i]=0;
        reach[i]=0;
    }
    printf("Enter in matrix form\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);
    while(1)
    {
        printf("Menu\n");
        printf("1.Test for reachability\n");
        printf("2.Test for connectivirt\n");
        printf("3.Exit\n");
        printf("Enter Your choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter valid vertex\n");
            scanf("%d",&v);
            if((v>1)||(v<1))
            {
                printf("Enter the valid vertex\n");
            }
            else{
                for(i=1;i<n;i++){
                    s[i]=0;
                    visited[i]=0;
                    reach[i]=0;
                }
                visited[v]=1;
                Reachability(v);
                printf("Rechable node from %d",v);
                for(i=1;i<=n;i++)
                if(visited[i]&&i!=v)
                printf("node %d\n",i);
            }
            break;
            case 2:for(i=1;i<=n;i++)
            reach[i]=0;
            Connectivity(1);
            if(count==n-1)
                printf("Graph is connected\n");
            else
                printf("Graph is not connected\n");
            break;
            case 3:return;
            default:printf("Invalid choice");

        }
        
    }

}
