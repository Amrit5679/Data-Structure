/*Menu driven program to perform operations on Double linked list*/
#include<stdio.h>
#include<stdlib.h>
struct dnode
{
    struct dnode *prev;
    int info;
    struct dnode *next;
};
typedef struct dnode DNODE;
DNODE * start=NULL;
void createDlist(DNODE *);
void traverseDlist(DNODE *);
void insert_after_dnode(DNODE *);
void delete_after_dnode(DNODE *);
main()
{
    DNODE *dnode;
    dnode=(DNODE *)malloc(sizeof(DNODE));
    if(dnode ==NULL)
    {
        printf("Memory allocation failed");
        exit(0);
    }
    start=dnode;
    int choice;
    printf("1.createDList\n 2.traverseDList\n 3.insert after dnode\n  4.Delete after dnode\n 5.EXIT\n");
    while(choice !=5)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                 createDlist(dnode);
                 break;
            case 2:
                 traverseDlist(dnode);
                 break;
            case 3:
                 insert_after_dnode(start);
                 break;
            case 4:
                 delete_after_dnode(start);
                 break;
            case 5:
                 printf("EXIT\n");
                 break;
            default:
                 printf("Invalid Input\n");
                 break;
        }
    }
}
void createDlist(DNODE *dnode)
{
    DNODE *new;
    int ch;
    printf("Enter a data:");
    scanf("%d",&dnode->info);
    dnode->prev=NULL;
    dnode->next=NULL;
    printf("\nPress 1 to continue and 0 to exit");
    scanf("%d",&ch);
    while(ch !=0)
    {
        new=(DNODE *)malloc(sizeof(DNODE));
        if(new==NULL)
        {
            printf("Memory allocation failed");
            exit(0);
        }
        printf("Enter the data:");
        scanf("%d",&new->info);
        dnode->next=new;
        new->prev=dnode;
        dnode=dnode->next;
        new->next=NULL;
        printf("\nPress 1 to continue and 0 to exit");
        scanf("%d",&ch);
    }
}
void traverseDlist(DNODE *dnode)
{
    DNODE *temp;
    printf("Double Linked list elements in forward direction\n");
    while(dnode !=NULL)
    {
        temp=dnode;
        printf("%d\t",temp->info);
        dnode=dnode->next;
    }
    printf("\nDouble Linked list elements in backward direction\n");
    while(temp !=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->prev;
    }
}
void insert_after_dnode(DNODE *dnode)
{
    int data;
    printf("Enter the info of node after which element to be inserted:");
    scanf("%d",&data);
    DNODE *new;
    new=(DNODE *)malloc(sizeof(DNODE));
    if(new ==NULL)
    {
        printf("\nMemory allocation failed");
        exit(0);
    }
    printf("Enter the node information:");
    scanf("%d",&new->info);
    while(dnode !=NULL)
    {
        if(dnode->info==data)
        {
            new->next=dnode->next;
            dnode->next=new;
            new->prev=dnode;
            dnode->next->prev=new;
            return 0;
        }
        dnode=dnode->next;
    }
    if(dnode ==NULL)
        {
            printf("Element is not found in the list");
            exit(0);
        }
}
void delete_after_dnode(DNODE *dnode)
{
    int data;
    printf("Enter the info of node after which element to be deleted:");
    scanf("%d",&data);
    DNODE *temp;
    start=dnode;
    while(dnode !=NULL)
    {
        if(dnode->info==data)
        {
            temp=dnode->next;
            dnode->next=temp->next;
            temp->next->prev=dnode;
            temp->prev=NULL;
            temp->next=NULL;
            free(temp);
            return 0;
        }
        dnode=dnode->next;
    }
    if(dnode ==NULL)
    {
        printf("Element is not found in the list");
    }
}
