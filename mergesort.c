#include<stdio.h>
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
void merge(int arr[],int low,int mid,int high){
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            b[k]=arr[i];
            i++,k++;
        }
        else{
            b[k]=arr[j];
            j++,k++;
        }
    }
    while(i<=mid){
        b[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        b[k]=arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++){
        arr[i]=b[i];
    }
}
void mergeSort(int arr[],int low,int high){
    int mid=(low+high)/2;
    if(low<high){
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[]={11,10,9,45,42,76,56};
    int n=7;
    printf("The original array is:\n");
    printArray(arr,n);
    printf("\n");
    mergeSort(arr,0,6);
    printf("The sorted array is:\n");
    printArray(arr,n);
}