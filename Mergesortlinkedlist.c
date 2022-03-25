
/*To create two single Linked list with value of nodes in ascending order.Write a function
to merge both the list into a single list so that all nodes will be in ascending order
Name-Amrit Mishra Sec-I1_21 Sic-20BCSE22 Date-28/06/2021*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE* start3=NULL;
void createList(NODE *);
void traverseList(NODE *);
NODE* mergelist(NODE *,NODE *,NODE *);
main()
{
    NODE *node1,*node2,*node3;
    node1=(NODE *)malloc(sizeof(NODE));
    node2=(NODE *)malloc(sizeof(NODE));
    node3=(NODE *)malloc(sizeof(NODE));
    start3=node3;
    createList(node1);
    traverseList(node1);
    createList(node2);
    traverseList(node2);
    mergelist(node1,node2,node3);
    printf("Merged");
    traverseList(start3);
}
void createList(NODE *node)
{
    int ch;
    printf("Enter a information of node in ascending order:");
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
        printf("Press 1 to continue and 0 to exit");
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
    printf("\n");
}
NODE* mergelist(NODE *p,NODE *q,NODE *r)
{
   if(p==NULL)
     return q;
   if(q==NULL)
     return p;
   if(p && q)
   {
       if(p->info <= q->info)
       {
           r=p;
           p=p->next;
       }
       else
       {
           r=q;
           q=q->next;
       }
   }
   start3=r;
   while(p && q)
   {
       if(p->info <= q->info)
       {
           r->next=p;
           p=p->next;
       }
       else
       {
           r->next=q;
           q=q->next;
       }
       r=r->next;
   }
   if(p==NULL)
     r->next=q;
   if(q==NULL)
     r->next=p;
   return start3;
}
