#include<stdio.h>
int main(void)
{
  int n,w;
  int a[100];
  int i,j;
  
  scanf("%d",&n);
  scanf("%d",&w);
  
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  
  int k,l;
  
  for(k=0;k<n-1;k++){
    for(l=n-1;l>k;l--){
      if(a[l-1]<a[l]){
        int temp=a[l];
        a[l]=a[l-1];
        a[l-1]=temp;
      }
    }
  }
  
  int x=0;
  int m;
  
  for(m=0;m<w;m++){
    x+=a[m];
  }
   printf("%d",x);
  return 0;
}