#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int B=20001,N=2e5+500;
int a[N],b[N],n,p[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=a[i-1]+B;
    for(int i=1;i<=n;i++)b[i]=a[n+1-i];
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=2;i<=n;i++)
    {
        int t=a[p[i]]+b[p[i]]-a[p[i-1]]-b[p[i-1]];
        if(t<=0)a[p[i]]+=-t+1;
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
}