#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vi t(n), a(n);
    rep(i,n) cin >> t.at(i) >> a.at(i);
    ll x=t.at(0), y=a.at(0);
    for(ll i=1; i<n; i++){
        ll r = max((x+t.at(i)-1)/t.at(i), (y+a.at(i)-1)/a.at(i));
        x = t.at(i)*r;
        y = a.at(i)*r;
    }
    cerr << "x:" << x << endl;
    cerr << "y:" << y << endl;
    cout << x+y << endl;
}