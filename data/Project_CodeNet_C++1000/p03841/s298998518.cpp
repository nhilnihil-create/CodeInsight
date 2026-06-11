#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=505;

int n,x[N],f[N],a[N*N+N];

bool cmp(int p,int q)
{
    return x[p]<x[q];
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]),f[i]=i;
    sort(f+1,f+n+1,cmp);
    int now=1;
    for (int i=1;i<=n;i++)
    {
        int w=f[i];a[x[w]]=w;
        for (int j=1;j<w;j++)
        {
            while (a[now]) now++;
            a[now]=w;
        }
        if (now>x[w]) {puts("No");return 0;}
    }
    for (int i=1;i<=n;i++)
    {
        int w=f[i];
        for (int j=1;j<=n-w;j++)
        {
            while (a[now]) now++;
            if (now<x[w]) {puts("No");return 0;}
            a[now]=w;
        }
    }
    puts("Yes");
    for (int i=1;i<=n*n;i++) printf("%d ",a[i]);
    return 0;
}