#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using Tuple = tuple<int, int, int>;


int main() {
    ll n,a,b; cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];

    ll ans = 0;
    rep(i, n-1) {
        ans += min((a*(x[i+1]-x[i])), b);
    }

    cout << ans << endl;
}
