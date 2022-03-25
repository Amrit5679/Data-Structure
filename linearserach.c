/*To search for elements in an array by using linear search
Name-Amrit Mishra Sec-I1,Roll-21 Branch-Cse SIC-20bcse22*/
#include<stdio.h>
int linearsearch(int [],int,int);
main()
{
    int arr[20],i,n,key,l;
    printf("Enter the number of elements of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The elements of array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("Enter the element to search:");
    scanf("%d",&key);
    l=linearsearch(arr,n,key);
    if(l==-1)
    {
       printf("%d is not found:",key);
    }
    else
    {
            printf("%d is found at %d position",key,l+1);
    }
}
int linearsearch(int a[],int x,int s)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(a[i]==s)
        {
            return i;
        }
    }
    return -1;
}
