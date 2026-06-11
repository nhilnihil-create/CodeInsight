#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep3(i, l, n) for (int i = l; i < n; ++i)
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define chmax(a, b) a = (a >= b ? a : b)
#define chmin(a, b) a = (a <= b ? a : b)
#define out(a) cout << a << endl
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())

ll fnk[2000][2000];

// 魔法はすべてのスライムの色を変える

void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    // make f(n, k) : 魔法k回使える n番目のスライムは何番のスライムから作るか(最小の)
    rep(i, n) fnk[i][0] = a[i];
    rep3(k, 1, n) { // 魔法を使う回数
        rep(i, n) {
            fnk[i][k] = min(fnk[i][k - 1], a[(i - k + n) % n]);
        }
    }
    
    // rep(k, n) { rep(i, n) cout << fnk[i][k] << " "; cout << endl; }
    
    ll ans = 1e18;
    rep(k, n) {
        ll tmp = 0;
        rep(i, n) {
            tmp += fnk[i][k];
        }
        // out(k << " " << tmp);
        chmin(ans, (ll)k * x + tmp);
    }
    
    out(ans);
}

int main() {
    solve();
}

