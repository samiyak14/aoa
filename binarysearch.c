#include <stdio.h>
int main()
{
    int a[]={1,2,3,4,10,18,19,20};
    int n=sizeof(a)/sizeof(a[0]);
    int key,low,high,mid;
    printf("Enter element to be searched : ");
    scanf("%d", &key);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<a[mid])
        {
            high=mid-1;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
        else
        {
            printf("Element %d found at position %d",key,mid);
            break;
        }
    }
    if(low>high)
    {
        printf("Element not found.");
    }
    return 0;
    
}