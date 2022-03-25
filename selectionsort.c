/*To sort element using selection sort function and display
Amrit Mishra SIC-20BCSE22 SEc-I1_21 Date-26/05/2021*/
#include<stdio.h>
void selection_sort(int [],int);
main()
{
    int arr[20],n,i;
    printf("Enter the number of elements of array:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The elements of array before sorting are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    selection_sort(arr,n);
    printf("The elements of array after sorting are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void selection_sort(int a[],int x)
{
    int i,j,temp,min;
    for(i=0;i<x-1;i++)
    {
         min=i;
         for(j=i+1;j<x;j++)
         {
             if(a[j]<a[min])
                 min=j;
         }
             if(min !=i)
             {
                 temp=a[i];
                 a[i]=a[min];
                 a[min]=temp;
            }
    }
}
