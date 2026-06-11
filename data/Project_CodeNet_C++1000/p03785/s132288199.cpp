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

    ll ans=1;

    sort(all(t));

    ll time=t[0],total=1;
    for(int i=1;i<n;i++){
        if(t[i] - time <= k && total < c) ++total;
        else{
            ++ans;
            total=1;
            time=t[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}