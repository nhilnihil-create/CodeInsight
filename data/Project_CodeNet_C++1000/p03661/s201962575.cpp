#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define MAX 0x7f7f7f7f
#define maxn 200000+10
LL a[maxn];
LL sum[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    LL s=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        s+=a[i];
        sum[i]=sum[i-1]+a[i];//---
    }
    LL minn=MAX;
    for(int i=1;i<n;i++)
    {
        minn=min(minn,abs((LL)(s-sum[i]-sum[i])));//---
    }
    printf("%lld\n",minn);
}
