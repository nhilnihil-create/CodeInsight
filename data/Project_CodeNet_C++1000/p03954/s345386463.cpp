#include<cstdio>
int n,m,i,l,r,a[1<<21];int f(){for(i=1;i<n;i++){if(a[n+i-1]>m==a[n+i]>m)return a[n+i]>m;if(a[n-i+1]>m==a[n-i]>m)return a[n-i]>m;}return a[1]>m;}main(){scanf("%d",&n);for(i=1;i<n+n;i++)scanf("%d",a+i);for(l=1,r=n+n-1;l<=r?1:!printf("%d",l);f()?l=m+1:r=m-1)m=(l+r)/2;}
