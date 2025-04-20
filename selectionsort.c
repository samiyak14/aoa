#include <Stdio.h>
#define MAX 20
void main()
{
  int a[MAX],n, i,j,min;
  printf("Enter the number of elements : ");
  scanf("%d", &n);
  printf("Enter the array : ");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }
  for(i=0;i<n;i++)
  {
    min=i;
    for(j=i+1;j<n;j++)
    {
      if(a[j]<a[min])
      {
        min=j;
      }
    }
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;
    
    printf("output after pass %d", i+1);
    for(int k=0;k<n;k++)
    {
      printf("%d\t", a[k]);
    }
  }
}