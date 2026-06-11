#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,T;
    cin>>n>>T;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];

    ll ans=T;
    for(int i=1;i<n;i++){
        ans+=min(T,t[i]-t[i-1]); 
    }
    
    cout<<ans<<endl;
    return 0;
}