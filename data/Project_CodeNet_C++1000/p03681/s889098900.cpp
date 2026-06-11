#include <bits/stdc++.h>
using namespace std;

#define MOD (long long)(1e9+7)

using ll = long long;

ll factmod(ll in)
{
    ll ret=1;
    for(;in>=1;in--)
    {
        ret*=in;
        ret%=MOD;
    }
    
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;cin>>n>>m;

    ll ans=0;

    if(abs(n-m)==1) ans=(factmod(n)*factmod(m))%MOD;
    else if(n==m) ans=(factmod(n)*factmod(m)*2)%MOD;

    cout<<ans<<"\n";

    return 0;
}
