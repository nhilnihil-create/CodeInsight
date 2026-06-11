#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll k,t,cnt=INF,before; cin>>k>>t;
    vector<ll> a(t);
    rep(i,t) cin>>a[i];
    ll maxi=*max_element(all(a));
    cout<<max(maxi-1-(k-maxi), 0LL)<<endl;
    return 0;
}