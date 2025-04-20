#include <stdio.h>
void swap(int a[], int i, int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

int partition(int a[], int low, int high)
{
    int x,i,j;
    x=a[high];
    i=low-1;
    for(j=low;j<=high-1;j++)
    {
        if(a[j]<x)
        {
            i=i+1;
            swap(a,i,j);
        }
    }
    swap(a,i+1,high);
    return i+1;
}

void quicksort(int a[],int low, int high)
{
    int q;
    if(low<high)
    {
        q=partition(a,low,high);
        quicksort(a,low,q-1);
        quicksort(a,q+1,high);
    }
}

void main()
{
    int a[20],i, n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a,0,n-1);
    
    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}