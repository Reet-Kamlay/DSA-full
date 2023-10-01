#include<stdio.h>
void printArray(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void selectionSort(int *arr,int n){
    printf("Running Selection sort algorithm.......");
    int indexOfMin,temp;
    for(int i=0;i<n-1;i++){
        indexOfMin=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[indexOfMin]){
                indexOfMin=j;
            }
            
        }
        temp=arr[i];
        arr[i]=arr[indexOfMin];
        arr[indexOfMin]=temp;
    }

}
int main(){
    int arr[]={12,11,34,45,42};
    int n=5;
    printf("The original array is :");
    printArray(arr,n);
    selectionSort(arr,n);
    printf("The sorted array is: ");
    printArray(arr,n);
    return 0;
}