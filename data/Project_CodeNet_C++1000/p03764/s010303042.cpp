#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll a[100010],b[100010];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%lld",&b[i]);
    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans += a[i]*(i-1);
        ans%=mod;
    }
    for(int i=1;i<=n;i++)
    {
        ans -= a[i]*(n-i);
        ans%=mod;
    }
    ll ans2 = 0;
    for(int i=1;i<=m;i++)
    {
        ans2 += b[i]*(i-1);
        ans2%=mod;
    }
    for(int i=1;i<=m;i++)
    {
        ans2 -= b[i]*(m-i);
        ans2 %= mod;
    }
    ans = (ans*ans2)%mod;
    cout<<ans<<endl;
    return 0;
}

