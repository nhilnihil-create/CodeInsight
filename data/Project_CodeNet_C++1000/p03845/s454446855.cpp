#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> t(n);
    ll sum=0;
    rep(i,n){
        cin>>t[i];
        sum+=t[i];
    }
    ll m; cin>>m;
    rep(i,m){
        ll p,x; cin>>p>>x;
        p--;
        cout<<sum-t[p]+x<<endl;
    }
    return 0;
}