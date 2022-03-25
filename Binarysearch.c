/*To search for elements in an array by using binary search*/
#include<stdio.h>
int binarysearch(int [],int,int);
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
    l=binarysearch(arr,n,key);
    if(l==-1)
    {
       printf("%d is not found:",key);
    }
    else
    {
            printf("%d is found at %d position",key,l+1);
    }
}
int binarysearch(int arr[],int max,int element)
{
      int low = 0, high = max - 1, middle;
      while(low <= high)
      {
            middle = (low + high) / 2;
            if(element > arr[middle])
                  low = middle + 1;
            else if(element < arr[middle])
                  high = middle - 1;
            else
                  return middle;
      }
      return -1;
}
