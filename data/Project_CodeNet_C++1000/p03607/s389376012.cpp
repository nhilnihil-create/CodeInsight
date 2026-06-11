#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    map<ll,int>mp;
    rep(i,n){
        mp[a[i]]^=1;
    }
    ll ans = 0;
    for(auto it=mp.begin();it!=mp.end();it++){
        auto p = *it;
        if(p.second==1)ans++;
    }
    cout << ans << endl;

    return 0;
}
