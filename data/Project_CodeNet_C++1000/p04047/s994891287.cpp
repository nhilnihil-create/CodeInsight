#include<stdio.h>
int main()
{  int n,a[200],i,j,t,s=0;
   scanf("%d",&n);
   for(i=0;i<2*n;i++)
   scanf("%d",&a[i]);
   for(i=0;i<2*n-1;i++)
   for(j=0;j<2*n-1-i;j++)
   if(a[j]>a[j+1])
   {  t=a[j];
      a[j]=a[j+1];
      a[j+1]=t;
   }
   for(i=0;i<2*n;i+=2)
   s=s+a[i];
   printf("%d",s);
}