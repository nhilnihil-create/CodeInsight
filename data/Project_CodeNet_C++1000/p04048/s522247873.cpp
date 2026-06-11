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
#define outa(a, n) rep(_, n) cout << a[_] << " "; cout << endl
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)

// http://drken1215.hatenablog.com/entry/2019/03/15/205900
// など

ll calc(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return -a; // 最後2 * b * (q - 1) + bとしたい
    ll q = a / b;
    ll ret = 2 * b * q;
    ret += calc(b, a % b);
    return ret;
}
int main() {
    ll n, x; cin >> n >> x;
    out(n + calc(n - x, x));
}
