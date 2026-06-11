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
    ll n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll ans = 0;
    rep(i,n-1){
        ll p = a[i]/2;
        ans += p;
        a[i] -= p*2;
        ll k = min(a[i],a[i+1]);
        ans += k;
        a[i]-=k;
        a[i+1]-=k;
    }
    ans += a[n-1]/2;
    cout << ans << endl;
    return 0;
}
