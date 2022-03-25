 /*To add two polynomials by using linked list.Represent each of the
polynomial with a linked list. The resultant polynomial should also be stored in a linked list
Name-Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-04/07/2021*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
       int coeff;
       int pow;
       struct node *next;
};
typedef struct node NODE;
NODE *poly1=NULL,*poly2=NULL,*poly=NULL;
void create(NODE *);
NODE *polyadd(NODE *,NODE *,NODE *);
void display(NODE *);
main()
{
      int ch;
      poly1=(NODE*)malloc(sizeof(NODE));
      poly2=(NODE*)malloc(sizeof(NODE));
      poly=(NODE*)malloc(sizeof(NODE));
      printf("\nEnter 1st Polynomial:");
      create(poly1);
      printf("\nEnter 2nd Polynomial:");
      create(poly2);
      printf("\n1st Polynomial:");
      display(poly1);
      printf("\n2nd Polynomial:");
      display(poly2);
      polyadd(poly1,poly2,poly);
      printf("\nAdded polynomial:");
      display(poly);
}
void create(NODE *node)
{
    int ch;
    do
    {
       printf("\n Enter the coeff:");
       scanf("%d",&node->coeff);
       printf("\n Enter the power:");
       scanf("%d",&node->pow);
       node->next=(NODE*)malloc(sizeof(NODE));
       node=node->next;
       node->next=NULL;
       printf("\nPress 1 to continue and zero to exit");
       scanf("%d",&ch);
    }
    while(ch !=0);
}
void display(NODE*node)
{
     while(node->next!=NULL)
     {
         printf("%dx^%d",node->coeff,node->pow);
         node=node->next;
         if(node->next!=NULL)
             printf("+");
      }
}
NODE *polyadd(NODE *poly1,NODE *poly2,NODE *poly)
{
     if(poly1==NULL)
        return poly2;
     if(poly2==NULL)
        return poly1;
     while(poly1->next &&  poly2->next)
     {
      if(poly1->pow>poly2->pow)
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff;
       poly1=poly1->next;
       }
      else if(poly1->pow<poly2->pow)
      {
       poly->pow=poly2->pow;
       poly->coeff=poly2->coeff;
       poly2=poly2->next;
       }
      else
      {
       poly->pow=poly1->pow;
       poly->coeff=poly1->coeff+poly2->coeff;
       poly1=poly1->next;
       poly2=poly2->next;
       }
      poly->next=(NODE*)malloc(sizeof(NODE));
      poly=poly->next;
      poly->next=NULL;
     }
     return poly;
}
