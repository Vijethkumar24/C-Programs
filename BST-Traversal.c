#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    return x;
}

NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    int i;
    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        prev = NULL;
        cur = root;
        while (cur != NULL)
        {
            prev = cur;
            cur = (temp->info < cur->info) ? cur->llink : cur->rlink;
        }
        if (temp->info < prev->info)
            prev->llink = temp;
        else if (temp->info > prev->info)
            prev->rlink = temp;
        return root;
    }
}

void pre(NODE PRE)
{
    if (PRE != NULL)
    {
        printf("%d", PRE->info);
        pre(PRE->llink);
        pre(PRE->rlink);
    }
}
void in(NODE IN)
{
    if (IN != NULL)
    {
        in(IN->llink);
        printf("%d", IN->info);
        in(IN->rlink);
    }
}
void post(NODE POST)
{
    if (POST != NULL)
    {
        post(POST->llink);
        in(POST->rlink);
        printf("%d", POST->info);
    }
}
void Traversal(NODE root)
{
    NODE IN, PRE, POST;
    IN = PRE = POST = root;
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    printf("Pre-order traversal\n");
    pre(PRE);
    printf("in-order traversal\n");
    in(IN);
    printf("post--order traversal\n");
    post(POST);
}
NODE Search(NODE root)
{
    NODE cur;
    int item;
    int i = 0;
    printf("Enter the item to be innseered\n");
    scanf("%d", &item);
    if (root == NULL)
    {
        printf("Tree is empty");
        return root;
    }
    cur = root;
    while (cur != NULL)
    {
        if (item == cur->info)
        {
            i++;
            printf("key found ");
        }
        if (item < cur->info)
           cur= cur->llink;
        else
           cur= cur->rlink;
    }
    if (i == 0)
        printf("unsucessful search\n");
    return root;
}
void main()
{
    NODE root;
    int ch, item, n;
    while (1)
    {
        printf("1.Bst\n");
        printf("2.Traversal\n");
        printf("3.Search\n");
        printf("4.Exit\n");
        printf("Enter the choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no of elements\n");
            scanf("%d", &n);
            while (n > 0)
            {
                printf("Enter the item\n");
                scanf("%d", &item);
                root = insert(item, root);
                n--;
            }
            break;
        case 2:
            Traversal(root);
            break;
        case 3:
            Search(root);
            break;
        case 4:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}
