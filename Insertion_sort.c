#include<stdio.h>
int insert_sort(int A[],int size);
int print_array(int A[],int size);
int main()
{
    printf("Enter the value of n");
    int n;scanf("%d",&n);
    int A[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    insert_sort(A,n);
    print_array(A,n);
}

int insert_sort(int A[],int size)
{
    for(int i=1;i<size;i++)
    {
        int j=i-1;int key=A[i];

        while(key<A[j]&&j>=0)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}

int print_array(int A[],int size)
{
    for(int i=0;i<size;i++)
        printf("%d\t",A[i]);
}
