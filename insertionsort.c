/*To sort element using insertion sort function and display
Amrit Mishra SIC-20BCSE22 SEc-I1_21 Date-26/05/2021*/
#include<stdio.h>
void insertion_sort(int [],int);
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
    printf("\n");
    insertion_sort(arr,n);
    printf("The elements of array after sorting are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
void insertion_sort(int a[],int x)
{
    int i,j,temp;
    for(i=0;i<=x-1;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
