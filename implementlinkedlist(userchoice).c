/*To implement linked list with more than one node.The user have options to insert a new node or exit the list
Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-31/5/2021*/
#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
void createList(NODE *);
void traverseList(NODE *);
void countnode(NODE *);
main()
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    createList(node);
    traverseList(node);
    countnode(node);

}
void createList(NODE *node)
{
    int ch;
    printf("Enter a data:");
    scanf("%d",&node->info);
    printf("\nPress 1 to continue and 0 to exit");
    scanf("%d",&ch);
    while(ch !=0)
    {
        node->next=(NODE*)malloc(sizeof(NODE));
        node=node->next;
        printf("Enter the data:");
        scanf("%d",&node->info);
        node->next=NULL;
        printf("\nPress 1 to continue and 0 to exit");
        scanf("%d",&ch);
    }
}
void countnode(NODE *node)
{
    int count=0;
    NODE *first=node;
    while(first !=NULL)
    {
        count++;
        first=first->next;
    }
    printf("\nNumber of nodes=%d",count);
}
void traverseList(NODE *first)
{
    printf("Linked list elements:\n");
    while(first !=NULL)
    {
        printf("%d\t",first->info);
        first=first->next;
    }
}

