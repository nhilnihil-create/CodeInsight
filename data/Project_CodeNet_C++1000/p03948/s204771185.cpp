#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long LL;
#define M(a,b) memset(a,b,sizesof(a))
#define pb push_back
int a[100005];
int Min(const int &a,const int &b)
{
    return a<b?a:b;
}
int Max(const int &a,const int &b)
{
    return a>b?a:b;
}
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for (int i=1;i<=n;++i)
        scanf("%d",a+i);
    int ma=0,mi=a[1];
    int cnt=1;
    for (int i=2;i<=n;++i)
    {
        if (ma==a[i]-mi)
            ++cnt;
        ma=Max(ma,a[i]-mi);
        mi=min(mi,a[i]);
    }
    printf("%d\n",cnt);
    return 0;
}
