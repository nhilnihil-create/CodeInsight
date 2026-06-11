#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    auto add=[&](ll &a,ll b){a=(a+(b%mod)+mod)%mod;};
    ll n;
    cin >> n;
    ll res=0;
    vector<ll> d(n+1,0);
    d[1]=1;
    if(n>=2) d[2]=mod-1;
    ll now=0;
    for(ll i=1;i<=n-1;i++)
    {
        add(now,d[i]);
        //cout << i << ": " << now << endl;
        add(res,(now*(n-1)%mod)*(n-1));
        add(res,(i+1-(i==n-1))*now);
        add(d[i+1],now);
        if(i+2<=n) add(d[i+2],-now);
        if(i+3<=n) add(d[i+3],now);
    }
    add(now,d[n]);
    //cout << n << ": " << now << endl;
    add(res,now*n);
    cout << res << "\n";
    return 0;
}
