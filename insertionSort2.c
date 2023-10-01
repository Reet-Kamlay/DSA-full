#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void insertionSort(int *arr,int n){
    int j,key;
    for(int i=0;i<=n-1;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[]={12,11,10,5,6,7};
    int n=6;
    printf("The original array is : ");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("The array after sorting is: ");
    printArray(arr,n);
}