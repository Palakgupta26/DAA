#include<stdio.h>
void insertionsort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<=n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int n;
    printf("enter the number of elements");
    scanf("%d",&n);

    int a[n];
    printf("enter %d elements\n",n);
    for(int i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
insertionsort(a,n);
printf("sorted array");
for(int i=0;i<=n;i++)
{
printf("%d",a[i]);
}
printf("/n");
}