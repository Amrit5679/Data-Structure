/*To implement stack by using Linked List
#include<stdio.h>
#include<stdbool.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE *top=NULL;
void push(int);
void pop();
void display();
main()
{
    int choice,x;
    printf("1.Push\n 2.Pop \n 3.Display\n 4.Exit\n");
    while(choice !=4)
    {
         printf("Enter your choice:\n");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1:
                 printf("Enter data to push into stack:");
                 scanf("%d",&x);
                 push(x);
                 break;
            case 2:
                 pop();
                 break;
            case 3:
                printf("The stack is:\n");
                display();
                break;
            case 4:
                printf("Exit\n");
                break;
            default:
                printf("Invalid Input");
                break;
       }
    }
}
void push(int x)
{
    NODE *new;
    new=(NODE*)malloc(sizeof(NODE));
    new->info=x;
    new->next=top;
    top=new;
}
void pop()
{
    NODE *temp;
    if(temp ==NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        temp=top;
        top=temp->next;
        printf("Deleted element is %d\n",temp->info);
        free(temp);
    }
}
void display()
{
   if(top == NULL)
      printf("Stack is Empty\n");
   else
   {
      NODE *temp = top;
      while(temp->next != NULL)
      {
	      printf("%d\t",temp->info);
	      temp = temp -> next;
      }
      printf("%d\tNULL",temp->info);
   }
}
