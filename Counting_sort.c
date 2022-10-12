#include<stdio.h>
void counting_sort(int A[],int size);
void print_array(int A[],int size);

int main()
{
    int size;
    printf("Enter the value of size\n");
    scanf("%d",&size);
    int A[size];
    for(int i=0;i<size;i++)
    {
        scanf("%d",&A[i]);
    }
    counting_sort( A,size);
    print_array(A,size);

}

void counting_sort(int A[],int size)
{
    int max=A[0];
    for(int i=1;i<size;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    int output[max+1];
     int count[max+1];
    for(int i=0;i<=max;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<size;i++)
    {
        count[A[i]]++;
    }

    for(int i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }

    for(int i=size-1;i>=0;i--)
    {
        output[count[A[i]]-1]=A[i];
        count[A[i]]--;
    }
    for(int i=0;i<size;i++)
        A[i]=output[i];
}
void print_array(int A[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d",A[i]);
}
