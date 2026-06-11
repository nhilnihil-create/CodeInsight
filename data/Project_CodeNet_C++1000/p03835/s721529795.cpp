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
    ll k,s,ans=0; cin>>k>>s;
    rep(i,k+1)rep(j,k+1){
        ll z=s-i-j;
        if(0<=z&&z<=k) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}