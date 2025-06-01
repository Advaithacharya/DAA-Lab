#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low, int mid,int high){
int i=low,j=mid+1,k=low;
int c[1000000];
while(i<=mid && j<=high){
if(a[i]<a[j]){
c[k]=a[i];
i++;
}
else{
c[k]=a[j];
j++;
}
k++;
}
while(i<=mid)
{
c[k++]=a[i++];
}
while(j<=high){
c[k++]=a[j++];
}
for(i=low;i<=high;i++){
a[i]=c[i];
}
}
void mergeSort(int a[],int low,int high){
if(low<high){
int mid=low+(high-low)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
merge(a,low,mid,high);
}
}
void main(){
int n,i,j,k,low,mid,high;
printf("Enter the no. of elements:");
scanf("%d",&n);
int a[n];
srand(time(NULL));
for(int i=0;i<n;i++){
a[i]=rand()%10000000;
}
clock_t start=clock();
mergeSort(a,0,n-1);
clock_t end=clock();
double timetaken=((double)(end-start)/CLOCKS_PER_SEC);
printf("Time taken in sec is: %f",timetaken);
}


