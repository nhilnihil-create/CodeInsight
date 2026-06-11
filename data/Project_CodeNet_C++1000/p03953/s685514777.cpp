#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int n,x[100100],m,d[100100],ans[100100],tmp[100100];long long K;
double a[100100];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i];
    cin>>m>>K;
    for(int i=1;i<=n;++i)d[i]=i,ans[i]=i;
    for(int i=1;i<=m;++i)
    {
    	int x;
        cin>>x;
        swap(d[x],d[x+1]);
    }
    while(K)
    {
        if(K&1)
        {
            for(int i=1;i<=n;++i)tmp[i]=ans[d[i]];
            for(int i=1;i<=n;++i)ans[i]=tmp[i];
        }
        for(int i=1;i<=n;++i)tmp[i]=d[d[i]];
        for(int i=1;i<=n;++i)d[i]=tmp[i];
        K>>=1;
    }
    for(int i=1;i<=n;++i)a[i]=x[ans[i]]-x[ans[i]-1];
    for(int i=1;i<=n;++i)printf("%.1lf\n",a[i]+=a[i-1]);
    return 0;
}