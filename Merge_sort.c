#include<stdio.h>
int merge_sort(int A[],int l,int h);
int merge(int A[],int l,int m,int r);
int print_array(int A[],int n);

int main()
{
    int n;
    printf("Enter the array size\n");
    scanf("%d",&n);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);

    merge_sort(A,0,n-1);
     printf("Print the sorted array");
     print_array( A,n);

}

int merge_sort(int A[],int l,int h)
{
    if(l<h)
    {
        int mid=l+(h-l)/2;

        merge_sort(A,l,mid);
        merge_sort(A,mid+1,h);

        merge(A,l,mid,h);
    }
}

int merge(int A[],int l,int mid,int h)
{
    int n1=mid-l+1;
    int n2=h-mid;
    int B[n1],C[n2];
    for(int i=0; i<n1; i++)
        B[i]=A[l+i];
    for(int j=0; j<n2; j++)
        C[j]=A[j+mid+1];

    int i=0,j=0,k=mid;

    while (i < n1 && j < n2)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i++;
        }
        else
        {
            A[k] = C[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = B[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        A[k] = C[j];
        j++;
        k++;
    }
}
int print_array(int A[],int n)
{

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
}
