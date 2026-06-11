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

ll sumofketa(ll a,ll b){
    string s=to_string(a),t=to_string(b);
    return max(s.size(),t.size());
}

int main(void)
{
    ll n; cin>>n;
    ll ans=INF;
    for(ll i=1;i<=sqrt(n);i++){
        if(n%i!=0) continue;
        ans=min(ans,sumofketa(i,n/i));
    }
    cout<<ans<<endl;
    return 0;
}