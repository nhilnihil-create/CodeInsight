#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,c,k; cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];

    ll ans=0;

    sort(all(t));

    for(int i=0;i<n;){
        ll start = i;
        while(i<n && t[i] - t[start] <= k && i - start < c) ++i;
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}