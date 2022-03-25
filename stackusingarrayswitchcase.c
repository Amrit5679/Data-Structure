/*To implement stack by using array (Menu driven program)
Name-Amrit Mishra Sec-I1_21 Sic-20BCSE22 Date-13/5/2021*/
#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1,x;
void push(int);
void pop();
int isFull();
int isEmpty();
void display();
int main()
{
    int choice;
    printf("1.Push\n 2.Pop \n 3.Display\n 4.Exit\n");
    while(choice !=4)
    {
         printf("Enter your choice:");
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
void push(int element)
{
    if(isFull() ==0)
    {
        top++;
        stack[top]=x;
    }
    else
    {
        printf("Stack is full");
    }
}
void pop()
{
    if(isEmpty())
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        x=stack[top];
        top--;
        printf("The popped element is %d\n",x);
    }
}
int isFull()
{
    if(top== MAX-1)
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
void display()
{
    int i;
    if(isEmpty())
    {
        printf("\nStack is empty:");
    }
    else
    {
        for(i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
