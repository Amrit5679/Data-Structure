/*Menu driven program to perform operations on linked list
Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-8/5/2021*/
#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE * start=NULL;
void createList(NODE *);
void traverseList(NODE *);
void delete_beg(NODE *);
void delete_end(NODE *);
void delete_pos(NODE *);
void delete_specificnode(NODE *);
main()
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    int choice;
    start=node;
    createList(node);
    traverseList(node);
    printf("\n1.Delete node at begining\n 2.Delete node at end\n 3.Delete at given position\n 4.Delete node after specific node\n 5.EXIT\n");
    while(choice !=5)
    {
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                delete_beg(node);
                traverseList(start);
                break;
            case 2:
                delete_end(node);
                traverseList(start);
                break;
            case 3:
                delete_pos(node);
                traverseList(start);
                break;
            case 4:
                delete_specificnode(node);
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
void delete_beg(NODE *node)
{
     NODE *temp;
     temp=node;
     node=node->next;
     free(temp);
     start=node;
}
void delete_end(NODE *node)
{
     NODE *prev;
     while(node->next !=NULL)
     {
         prev=node;
         node=node->next;
     }
     prev->next=NULL;
     if(node->next ==NULL);
     {
         free(node);
     }
}
void delete_pos(NODE *node)
{
    int count,pos,i=1;
    NODE *temp;
    temp=node;
    while(temp !=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("Enter the position to delete the node:");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Enter a valid position:");
        exit(0);
    }
    NODE *prev;
    while(i<pos)
    {
        prev=node;
        node=node->next;
        i++;
    }
    if(pos ==1)
    {
        start=node->next;
        free(node);
    }
    else
    {
        prev->next=node->next;
        node->next=NULL;
        free(node);
    }
}
void delete_specificnode(NODE *node)
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
        }
        node=node->next;
    }
    if(node ==NULL)
    {
        printf("Element is not found in the list");
    }
}
