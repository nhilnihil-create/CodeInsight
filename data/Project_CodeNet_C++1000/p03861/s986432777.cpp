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

ll f(ll n,ll x){
    if(n<0) return 0;
    else return n/x+1;
}

int main(void)
{
    ll a,b,x; cin>>a>>b>>x;
    if(a==0) cout<<b/x+1<<endl;
    else cout<<b/x-(a-1)/x<<endl;
    return 0;
}