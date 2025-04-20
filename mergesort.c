#include <stdio.h>
int a[20], n ,i ,j;
void merge(int, int);
void msort(int,int,int);
void display();

void main()
{
  printf("Enter the number of elements : ");
  scanf("%d", &n);
  
  printf("Enter the array : ");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  
  merge(0,n-1);
  display();
}

void merge(int low, int high)
{
  int mid=(low+high)/2;
  if(low!=high)
  {
      merge(low,mid);
      merge(mid+1,high);
      msort(low,mid,high);
     display();
     printf("\n");
  }
}

void msort(int low,int mid, int high)
{
  int temp[20],i=low,j=mid+1,k=low;
  while(i<=mid && j<=high)
  {
    if(a[i]<a[j])
    {
      temp[k++]=a[i++];
    }
    else
    {
      temp[k++]=a[j++];
    }
  }
  while(i<=mid)
  {
    temp[k++]=a[i++];
  }
  while(j<=high)
  {
    temp[k++]=a[j++];
  }
  for(i=low;i<=high;i++)
  {
    a[i]=temp[i];
  }
}

void display()
{
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}