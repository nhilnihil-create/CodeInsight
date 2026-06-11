#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define rrep1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, k, a[100010];

template<typename T>
T gcd(T x, T y) {
    if (y==0) return x;
    return gcd(y, x % y);
}

template<typename T>
T lcm(T x, T y) {
    T g = gcd(x, y);
    return x / g * y;
}

int main() {
    cin >> n >> k;
    rep(i, n) cin >> a[i];

    int g = a[0];
    rep(i, n) {
        if (i == 0) continue;
        g = gcd(g, a[i]);
    }

    int m = -1;
    rep(i, n) chmax(m, a[i]);
    if (k % g == 0 && k <= m) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}
