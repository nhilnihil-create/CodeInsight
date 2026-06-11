#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;


int main(){
    ll n,k;
    cin >> n >> k;
    vector<P>v(n);
    rep(i,n){
        ll a,b;cin >> a >> b;
        v[i]={a,b};
    }
    ll now = 0;
    sort(v.begin(),v.end());
    rep(i,n){
        now += v[i].second;
        if(now>=k){
            cout << v[i].first << endl;
            return 0;
        }
    }

}
