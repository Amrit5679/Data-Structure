/*TO search for a particular node in a linked list.Show the location of the node
 if it is found otherwise show the message "node not found"
 Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-3/5/2021*/
 #include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
void createList(NODE *);
void traverseList(NODE *);
int searchnode(NODE *,int);
int main()
{
    int l,ele;
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    createList(node);
    traverseList(node);
    printf("Enter the node's info to search:");
    scanf("%d",&ele);
    l=searchnode(node,ele);
    if (l==-1)
        printf("Node is not found");
    else
         printf("Node is Found");
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
int searchnode(NODE *node,int data)
{
    while(node != NULL)
    {
        if(node->info == data)
            return 0;
        node=node->next;
    }
    return -1;
}
