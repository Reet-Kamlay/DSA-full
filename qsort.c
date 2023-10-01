#include<stdio.h>
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int partition(int arr[],int low,int high){
    int i,j,pivot,temp;
    pivot=arr[low];
    i=low+1;
    j=high;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}
void qsort(int arr[],int low,int high){
    int partitionindex;
    if(low<high){
        partitionindex=partition(arr,low,high);
        qsort(arr,low,partitionindex-1);
        qsort(arr,partitionindex+1,high);
    }
}
int main(){
    int arr[]={12,11,10,34,32,65,62};
    int n=7;
    printf("The original array is:\n");
    printArray(arr,n);
    qsort(arr,0,n-1);
    printf("\n");
    printf("The sorted array is:\n");
    printArray(arr,n);
    return 0;
}