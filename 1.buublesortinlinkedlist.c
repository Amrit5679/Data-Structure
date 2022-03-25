 /*To sort nodes of singlelinkedlist in ascending order by using bubble sort algorithm
Name-Amrit Mishra Sec-I1_21 Sic-20BCSE22 Date-23/06/2021*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE * start=NULL;
void createList(NODE *);
void traverseList(NODE *);
void bubble_sort(NODE *);
main()
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    start=node;
    createList(node);
    traverseList(node);
    bubble_sort(node);
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
void traverseList(NODE *first)
{
    printf("Linked list elements:\n");
    while(first !=NULL)
    {
        printf("%d\t",first->info);
        first=first->next;
    }
}
void bubble_sort(NODE *node)
{
    NODE *p,*q;
    int temp;
    start=node;
    for(p=start;p->next !=NULL;p=p->next)
    {
        for(q=start;q->next !=NULL;q=q->next)
        {
            if(q->info > q->next->info)
            {
                 temp=q->info;
                 q->info=q->next->info;
                 q->next->info=temp;
            }
        }
    }
    printf("\nSorted elements of Linked list are:\n");
    while(node !=NULL)
    {
        printf("%d\t",node->info);
        node=node->next;
    }
}
