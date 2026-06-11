#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define maxn 100005
const ll mod=1e9+7;
using namespace std;
ll x[maxn];
int n,m;
ll y[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&y[i]);
        ll  ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            ans1=(ans1+(i-1)*x[i]+mod)%mod;
            ans1=(ans1-(n-i)*x[i]+mod)%mod;
        }
        for(int i=1;i<=m;i++)
        {
            ans2=(ans2+(i-1)*y[i]+mod)%mod;
            ans2=(ans2-(m-i)*y[i]+mod)%mod;
        }
        printf("%lld\n",(ans1%mod*ans2%mod)%mod);
        return 0;
}
