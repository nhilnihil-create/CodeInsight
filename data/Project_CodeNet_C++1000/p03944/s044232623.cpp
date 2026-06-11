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
ll w,h,n;
cin >> w >> h >> n;
vector<ll> x(n), y(n), a(n);
ll grid[h][w];
for (ll i = 0; i < h;i++){
    for (ll j = 0; j < w;j++){
        grid[i][j] = 0;
    }
}
for (ll i = 0; i < n; i++) cin >> x[i] >> y[i] >> a[i];
for (ll i = 0; i < n; i++) {
    if (a[i] == 1) {
        for (ll j = 0; j < h; j++) {
            for (ll k = 0; k < x[i]; k++) {
                grid[j][k] = 1;
            }
        }
    } else if (a[i] == 2) {
        for (ll j = 0; j < h; j++) {
            for (ll k = x[i]; k < w; k++) {
                grid[j][k] = 1;
            }
        }
    } else if (a[i] == 3) {
        for (ll j = 0; j < y[i]; j++) {
            for (ll k = 0; k < w; k++) {
                grid[j][k] = 1;
            }
        }
    } else {
        for (ll j = y[i]; j < h; j++) {
            for (ll k = 0; k < w; k++) {
                grid[j][k] = 1;
            }
        }
    }
}
ll cnt = 0;
for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w;j++){
        if (grid[i][j] == 0) cnt++;
    }
}
cout << cnt << endl;
}