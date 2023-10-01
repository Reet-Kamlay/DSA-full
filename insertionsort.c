#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
void insertionSort(int *A,int n){
    int j,key;
    for(int i=1;i<=n-1;i++){
        key=A[i];
        j=i-1;
        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;

    }
}
int main(){
    int arr[]={12,11,7,89,82,56};
    int n=6;
    printf("The original array is: ");
    printArray(arr,n);
    insertionSort(arr,n);
    printf("The modified array is: ");
    printArray(arr,n);
    return 0;
}