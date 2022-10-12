#include<stdio.h>
int partition(int arr[],int l,int h)
{
    int pivot=arr[l];
    int i=l-1,j=h+1;

    while(i<j)
    {
        do
        {
            i++;
        }
        while(arr[i]<=pivot);
        do
        {
            j--;
        }
        while(arr[j]>pivot);
        if(i<j)
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        int temp=arr[l];
        arr[l]=arr[j];
        arr[j]=temp;
        return j;
    }
}
int quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int j=partition(arr,l,h);
        quicksort(arr,l,j);
        quicksort(arr,j+1,h);
    }
}
int main()
{
    printf("Enter the value of n");
    int size;
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements\n");
    for(int i=0; i<size; i++)
        scanf("%d",&arr[i]);
    int h=size-1;
    int l=0;
    partition(arr,l,h);
    quicksort(arr,0,h);
    for(int i=0; i<size; i++)
        printf("%d  ",arr[i]);
}

