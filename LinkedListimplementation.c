/*Menu driven program to perform operations on linked list
Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-8/5/2021*/
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
void insert_beg(NODE *);
void insert_end(NODE *);
void insert_pos(NODE *);
void insert_specificnode(NODE *);
main()
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    int choice;
    start=node;
    createList(node);
    traverseList(node);
    printf("\n1.Insert node at begining\n 2.Insert node at end\n 3.Insert at given position\n 4.Insert node after specific node\n 5.EXIT\n");
    while(choice !=5)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert_beg(node);
                traverseList(start);
                break;
            case 2:
                insert_end(node);
                traverseList(node);
                break;
            case 3:
                insert_pos(node);
                traverseList(start);
                break;
            case 4:
                insert_specificnode(node);
                traverseList(start);
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Invalid Input");
                break;
        }

    }
}
void createList(NODE * node)
{
    int ch;
    printf("Enter a data:");
    scanf("%d",&node->info);
    printf("Press 1 to continue and 0 to exit");
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
void insert_beg(NODE *node)
{
    NODE *new;
    new=(NODE *)malloc(sizeof(NODE));
    if(new ==NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    printf("Enter the node information:");
    scanf("%d",&new->info);
    new->next=node;
    start=new;
}
void insert_end(NODE *node)
{
    NODE *new;
    new=(NODE *)malloc(sizeof(NODE));
    if(new ==NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    printf("Enter the node information:");
    scanf("%d",&new->info);
    new->next=NULL;
    while(node->next !=NULL)
    {
        node=node->next;
    }
    node->next=new;
}
void insert_pos(NODE *node)
{
    int count,pos,i=1;
    NODE *temp;
    temp=node;
    while(temp !=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Enter the position to insert the node:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Enter a valid position:");
        exit(0);
    }
    NODE *prev,*new;
    new=(NODE *)malloc(sizeof(NODE));
    if(new ==NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    printf("Enter the node information:");
    scanf("%d",&new->info);
    while(i<pos)
    {
        prev=node;
        node=node->next;
        i++;
    }
    if(pos==1)
    {
        new->next=node;
        start=new;
    }
    else
    {
        prev->next=new;
        new->next=node;
    }
}
void insert_specificnode(NODE *node)
{
    int data;
    printf("Enter the info of node after which element to be inserted:");
    scanf("%d",&data);
    NODE *new;
    new=(NODE *)malloc(sizeof(NODE));
    if(new ==NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    printf("Enter the node information:");
    scanf("%d",&new->info);
    start=node;
    while(node != NULL)
    {
        if(node->info==data)
        {
            new->next=node->next;
            node->next=new;
            return 0;
        }
        node=node->next;
    }
    if(node ==NULL)
    {
        printf("Element is not found in the list\n");
    }
 }
