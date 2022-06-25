#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int size=10;
void readarray(int arr[],int n){
    int i;
    for(i=1;i<=n;i++){
        arr[i]=rand()%20;
    }
}
void displayarray(int arr[],int n){
        int i;
    for(i=1;i<=n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
void merge(int arr[],int beg,int mid,int end){
    int i=beg,j=mid+1,index=beg,temp[size],k;
    while((i<=mid) && (j<=end)){
        if(arr[i]<arr[j]){
            temp[index]=arr[i];
            i++;
        }
        else{
                temp[index]=arr[j];
            j++;
        }
        index++;
    }
    if(i>mid){
        while(j<=end){
            temp[index]=arr[j];
            j++;
            index++;
        }
    }
    else{
        while(i<=mid){
            temp[index]=arr[i];
            i++;
            index++;
        }
    }
    for(k=beg;k<index;k++){
        arr[k]=temp[k];
    }
}
void merge_sort(int arr[],int low,int high){
    int mid;
    if(low<high){
            mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[size];
    readarray(arr,size);
    displayarray(arr,size);
    printf("\nSorted array:\n");
    merge_sort(arr,1,size);
    displayarray(arr,size);
    /*clock_t begin=clock();
    merge_sort(arr,1,size);
    clock_t end=clock();
    double time_spent=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\n Time taken for merge:%f\n",time_spent);*/
}
