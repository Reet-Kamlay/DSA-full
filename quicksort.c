#include <stdio.h>
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    pivot = arr[low];
    i = low + 1;
    j = high;
    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void qSort(int arr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        qSort(arr, low, partitionIndex - 1);
        qSort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 10, 6, 7, 8, 9};
    int n = 8;
    printf("The original array is:\n");
    printArray(arr, n);
    printf("\n");
    qSort(arr, 0, n - 1);
    printf("The sorted array is:\n");
    printArray(arr, n);
    return 0;
}