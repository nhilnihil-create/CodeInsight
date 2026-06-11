#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
#define ll long long
const ll inf=1e12;
int n;
using namespace std;
ll a[maxn];
ll sum[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
        ll minn=inf;
    for(int i=1;i<n;i++)
    {
        minn=min(minn,abs(sum[n]-2*sum[i]));

    }
    printf("%lld\n",minn);
    return 0;
}
