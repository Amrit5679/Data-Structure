/*Menu driven program to perform operations on circular linked list
Name-Amrit Mishra Sec-I1_21 Sic-20BCSE22 Date-21/06/2021*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE * start=NULL;
void createcircularList(NODE *);
void traversecircularList(NODE *);
void insert_after_node(NODE *);
void delete_after_node(NODE *);
main()
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    start=node;
    int choice;
    printf("1.createcircularList\n 2.traversecircularList\n 3.insert_after_node\n  4.Delete after node\n 5.EXIT\n");
    while(choice !=5)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:
                 createcircularList(node);
                 break;
             case 2:
                 traversecircularList(node);
                 break;
             case 3:
                 insert_after_node(node);
                 break;
             case 4:
                 delete_after_node(start);
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
void createcircularList(NODE *node)
{
    int ch;
    printf("Enter a data:");
    scanf("%d",&node->info);
    node->next=start;
    printf("Press 1 to continue and 0 to exit");
    scanf("%d",&ch);
    while(ch !=0)
    {
        node->next=(NODE*)malloc(sizeof(NODE));
        node=node->next;
        printf("Enter the data:");
        scanf("%d",&node->info);
        node->next=start;
        printf("Press 1 to continue and 0 to exit");
        scanf("%d",&ch);
    }
}
void traversecircularList(NODE *node)
{
    printf("Linked list elements are:\n");
    do
    {
        printf("%d\t",node->info);
        node=node->next;
    }while(node !=start);
}
void insert_after_node(NODE *node)
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
    while(node !=NULL)
    {
        if(node->info==data)
        {
            new->next=node->next;
            node->next=new;
            return 0;
        }
        node=node->next;
        if(node->next ==start)
        {
            node->next=new;
            new->next=start;
            return 0;
        }
    }
    if(node ==NULL)
        {
            printf("Element is not found in the list");
            exit(0);
        }
}
void delete_after_node(NODE *node)
{
    int data;
    printf("Enter the info of node after which element to be deleted:");
    scanf("%d",&data);
    NODE *temp;
    start=node;
    while(node !=NULL)
    {
        if(node->info==data)
        {
            temp=node->next;
            node->next=temp->next;
            free(temp);
            return 0;
        }
        node=node->next;
    }
    if(node ==NULL)
    {
        printf("Element is not found in the list");
    }
}
