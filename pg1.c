#include<stdio.h>
#include<time.h>
void main()
{
int i,n,j,k,temp;
printf("Enter the number of elements:\n");
scanf("%d",&n);
int a[n];
printf("Enter  elements");
srand(time(NULL));
for(i=0;i<n;i++)
{
a[i]=rand()%25000;
}
clock_t start=clock();
for(i=0;i<n;i++)
{
j=i;
for(k=i+1;k<n;k++)
{
if(a[k]<a[j])
{
temp=a[j];
a[j]=a[k];
a[k]=temp;
}
}
}
clock_t end=clock();
double time_taken=((double)(end-start))/CLOCKS_PER_SEC;
printf("Time taken is %F ",time_taken);
}
