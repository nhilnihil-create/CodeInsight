#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n);
    rep(i, n){
        cin >> x[i];
    }

    ll ans = 0; 
    rep(i, n-1){
        ans += min((x[i+1]-x[i])*a, b);
    }

    cout << ans << endl;

    return 0;
}