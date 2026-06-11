#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }



int main() {
    ll n,t; cin >> n >> t;
    vector<ll> tv(n);
    rep(i, n) cin >> tv[i];


    ll ans = 0;
    ll start = 0;
    ll end = 0;
    rep(i, n) {
        if(tv[i] > end) {
            ans += end-start;
            start = tv[i];
            end = start + t;
        } else {
            end = tv[i] + t;
        }
    }

    ans += end-start;
    cout << ans << endl;

    return 0;
}
