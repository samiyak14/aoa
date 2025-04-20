#include <stdio.h>
#define MAX 20
void main()
{
  int i,j,key,a[MAX],n;
  printf("Enter the number of elements : ");
  scanf("%d", &n);
  printf("Enter the array : ");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
    
  }
  for(j=1;j<n;j++)
  {
    key=a[j];
    i=j-1;
    while(i!=0 && a[i]>key)
    {
      a[i+1]=a[i];
      i=i-1;
    }
    a[i+1]=key;
    
    printf("Output after pass %d : ",j+1);
    for(int k=0;k<n;k++)
    {
      printf("%d\t", a[k]);
    }
  }
}