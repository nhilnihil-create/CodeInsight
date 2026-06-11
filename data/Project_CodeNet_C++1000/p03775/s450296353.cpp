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

ll keta(ll m,ll n){
    string s=to_string(m),t=to_string(n);
    return max(s.size(),t.size());
}

int main(void)
{
    ll n; cin>>n;
    ll ans=INF;
    for(int i=1;i<=sqrt(n);i++){
        ll b=n/i;
        if(b*i==n) ans=min(ans,keta(i,b));
    }
    cout<<ans<<endl;
    return 0;
}