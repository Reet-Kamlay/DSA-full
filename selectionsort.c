#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void selectionSort(int *arr,int n){
    printf("Running selection sort algorithm........");
    int indexofmin,temp;
    for(i=0;i<n-1;i++){
        indexofmin=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[indexofmin]){
                indexofmin=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[indexofmin];
        arr[indexofmin]=temp;
    }
}