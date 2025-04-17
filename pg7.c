#include<stdio.h>
#define MAX_ITEMS 10
int  knapSack(int W,int wt[],int val[],int n)
{
int i,j;
int v[MAX_ITEMS+1][W+1];
for(i=0;i<=n;i++){    
for(j=0;j<=W;j++){
if(i==0||j==0){
v[i][j]=0;
}
else if(j-wt[i]<0){
v[i][j]=v[i-1][j];
}else{
v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
}
}
}
return v[n][W];
}
int max(int a,int b){
return (a>b)?a:b;
}
int main(){
int i,n,wt[10],val[10],W;
printf("Enter the number of items\n");
scanf("%d",&n);
printf("Entre the Weight and value of items\n");
for(i=0;i<n;i++)
{
scanf("%d %d",&wt[i],&val[i]);
}
printf("Enter the weight capacity\n");
scanf("%d",&W);
printf("The max profit is %d",knapSack(W,wt,val,n));
}
