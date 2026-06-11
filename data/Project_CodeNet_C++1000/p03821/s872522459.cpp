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
    ll a[n], b[n];
    for (ll i = 0; i < n;i++){
        cin >> a[i] >> b[i];
    }
    ll cnt = 0;
    for (ll i = n - 1; i > 0; i--) {
        ll tmp = 0;
        tmp -= a[i];
        tmp += ((a[i] + b[i] - 1) / b[i]) * b[i];
        cnt += tmp;
        a[i - 1] += cnt;
    }
        ll tmp = 0;
        tmp -= a[0];
        tmp += ((a[0] + b[0] - 1) / b[0]) * b[0];
        cnt += tmp;
    cout << cnt << endl;
}