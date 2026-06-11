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
string s, t;
cin >> n >> s >> t;
ll ans = INF;
for (ll i = n - 1; i > -1; i--) {
    if (s.substr(i, n - i) == t.substr(0, n - i)) chmin(ans, n + i);
}
chmin(ans, 2 * n);
cout << ans << endl;
}