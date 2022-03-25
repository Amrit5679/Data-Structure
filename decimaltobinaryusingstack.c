/*To convert decimal number to binary number using stack
Name -Amrit Mishra Sec-I1_21 Sic -20BCSE22*/
#include<stdio.h>
#define MAX 20
int stack[MAX];
int top=-1;
void push(int);
int pop();
void dectobinary(int);
main()
{
    int num;
    printf("Enter a decimal number:\n");
    scanf("%d",&num);
    dectobinary(num);
}
void push(int num)
{
    if(top ==MAX-1)
    {
        printf("Stack is full");
        return;
    }
    top++;
    stack[top]=num;
}
int pop()
{
    if(top == -1)
    {
         printf("\nStack is Empty\n");
    }
    else
    {
        int n;
        n=stack[top];
        top--;
        return n;
    }
}
void dectobinary(int n)
{
    int rem;
    while(n !=0)
    {
        rem=n%2;
        push(rem);
        n=n/2;
    }
    printf("Binary equivalent is\n");
    while(top != -1)
        printf("%d",pop());
}
