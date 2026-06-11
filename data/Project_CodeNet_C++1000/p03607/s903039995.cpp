#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define inf 1e18
#define pi acos(-1.0)
#define mod 998244353

map<ll,ll>m;
map<ll,ll>:: iterator it;

int main(void)
{
    fastio;

    ll n,a,ans=0;
    cin >> n;
    while(n--)
    {
        cin >> a;
        m[a]++;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        if((it->second)%2)ans++;
    }
    cout << ans ;

    return 0;
}
