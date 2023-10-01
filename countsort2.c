#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int maximum(int arr[],int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    return max;
}
void countsort(int arr[],int n){
    int i,j;
    int max=maximum(arr,n);
    int *count=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<max+1;i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[arr[i]]=count[arr[i]]+1;
    }
    i=0;
    j=0;
    while(i<=max){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main()
{
    int arr[] = {12, 11, 10, 23, 22, 45};
    int n = 6;
    printf("The original array is:\n");
    printArray(arr, n);
    printf("\n");
    countsort(arr, n);
    printf("The sorted array is:\n");
    printArray(arr, n);
}