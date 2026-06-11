#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
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
int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    pair<bool, ll> flag;
    ll ans = 0;
    for (ll i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    for (ll i = 0; i < n; i++) {
        ans += a[i];
        if (a[i] % 10) {
            flag.first = true;
            flag.second = i;
        }
    }
    if(!(ans%10)){
        if (flag.first)
            ans -= a[flag.second];
        else
            ans = 0;
    }
    cout << ans << endl;
}
