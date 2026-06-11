#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    ll m=h+w;
    vector<ll> f(m+1,1);
    for(ll i=1;i<=m;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(m+1,1);
    finv[m]=fpow(f[m],mod-2);
    for(ll i=m-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto ch=[&](ll n,ll k)->ll
    {
        ll res=f[n];
        res=(res*finv[k])%mod;
        res=(res*finv[n-k])%mod;
        return res;
    };
    ll res=0;
    for(int o=1;o<=h-a;o++) res=(res+ch(o+b-2,b-1)*ch(h+w-o-(b+1),w-(b+1)))%mod;
    cout << res << "\n";
    return 0;
}
