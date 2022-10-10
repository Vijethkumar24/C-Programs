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
        printf("tree is empty\n");
        return;
    }
    printf("Pre order traversal\n");
    pre(PRE);
    printf("inorder traversal\n");
    in(IN);
    printf("pstorder traversal\n");
    post(POST);
}
NODE Search(NODE root)
{
    NODE cur;
    int item;
    int i = 0;
    printf("enter the item to be innseered\n");
    scanf("%d", &item);
    if (root == NULL)
    {
        printf("tree is empty");
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
        printf("1.bst\n");
        printf("2.traversal\n");
        printf("3.search\n");
        printf("4.exit\n");
        printf("enter the choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("no of elements\n");
            scanf("%d", &n);
            while (n > 0)
            {
                printf("enter the item\n");
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
            printf("invalid choice\n");
        }
    }
}