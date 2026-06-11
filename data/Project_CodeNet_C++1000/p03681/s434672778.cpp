#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const ll mod = 1e9+7;
ll n , m;

int main() {
    cin >> n >> m;
    ll ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans *= i;
        ans %= mod;
    }
    for(int i = 1; i <= m; ++i) {
        ans *= i;
        ans %= mod;
    }
    if(n == m) {
        ans *= 2;
        ans %= mod;
    }else if(abs(n-m) == 1) {

    }else {
        ans = 0;
    }
    cout << ans << endl;
}