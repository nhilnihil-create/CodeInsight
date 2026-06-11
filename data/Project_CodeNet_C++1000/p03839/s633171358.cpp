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
#define outa(a, n) { rep(_, n) cout << a[_] << " "; cout << endl; }
#define outp(a, n) { cout << endl; rep(_, n) cout << a[_].F << " " << a[_].S << endl; }
#define SZ(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
#define FIX(a) fixed << setprecision(a)
#define LB(v, n) (int)(lower_bound(all(v), n) - v.begin())
#define UB(v, n) (int)(upper_bound(all(v), n) - v.begin())

// http://drken1215.hatenablog.com/entry/2019/03/03/205300

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), acc(n + 1, 0), plus(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        acc[i + 1] = acc[i] + a[i];
        plus[i + 1] = plus[i] + (a[i] > 0 ? a[i] : 0);
    }
    ll res = -(1LL << 60);
    for (int i = 0; i + k <= n; ++i) { // 区間の右端(開区間)が範囲の1つ外まで
        int l = i, r = i + k;
        ll tmp = (plus[l] - plus[0]) + (plus[n] - plus[r]);
        tmp += max(0LL, acc[r] - acc[l]); // 最後連続kを白にするか黒にするか
        chmax(res, tmp);
    }
    
    out(res);
}
