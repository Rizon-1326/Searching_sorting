#include<stdio.h>
int Binary_search(int A[],int first, int last,int x)
{
    int mid;
    if(last>=first)
       {
            mid=first+(last-first)/2;

    if(A[mid]==x)
        return mid;
    else if(A[mid]>x)
        return Binary_search(A,first,mid-1,x);
    else if(A[mid]<x)return Binary_search(A,mid+1,last,x);
       }

        return -1;
}
int main()
{
    int n;
    printf("Enter the size of array");
    scanf("%d",&n);
    int A[n];
    for(int i=1;i<=n;i++)
        scanf("%d",&A[i]);

    int x=5;
    int result=Binary_search(A,1,n,x);
    if(result==-1)
        printf("Not found");
    else
        printf("%d is Found",x);


}
