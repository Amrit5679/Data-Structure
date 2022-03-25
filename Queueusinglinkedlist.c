/*To implement queue using Linked List
Amrit Mishra Sec-I1_21 Sic-20bcse22 Date-1/7/2021*/
#include<stdio.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NODE;
NODE *front=NULL;
NODE *rear=NULL;
void insert(int);
void delete();
void display();
main()
{
    int choice,x;
    printf("1.Insert\n 2.Delete \n 3.Display\n 4.Exit\n");
    while(choice !=4)
    {
         printf("Enter your choice:\n");
         scanf("%d",&choice);
         switch(choice)
         {
            case 1:
                 printf("Enter data to insert into queue:");
                 scanf("%d",&x);
                 insert(x);
                 break;
            case 2:
                 delete();
                 break;
            case 3:
                printf("The queue is:\n");
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
void insert(int x)
{
    NODE *new;
    new=(NODE*)malloc(sizeof(NODE));
    new->next=NULL;
    new->info=x;
    if(rear == NULL)
    {
        front=new;
        rear=new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
}
void delete()
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        NODE *temp;
        temp=front;
        front=front->next;
        printf("Deleted element is %d\n",temp->info);
        free(temp);
    }
}
void display()
{
   if(front == NULL)
      printf("Queue is Empty\n");
   else
   {
      NODE *temp = front;
      while(temp->next != NULL)
      {
          printf("%d\t",temp->info);
	      temp = temp -> next;
      }
      printf("%d\tNULL\n",temp->info);
   }
}
