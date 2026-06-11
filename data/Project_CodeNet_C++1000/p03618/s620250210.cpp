#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

int main(){
    string a;
    cin >> a;
    ll l = a.size();
    ll ans = l*(l-1)/2;
    map<char,ll>mp;
    rep(i,l){
        mp[a[i]]++;
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        ll now = it->second;
        ans -= now*(now-1)/2;
    }
    ans++;
    cout << ans << endl;
    return 0;
}
