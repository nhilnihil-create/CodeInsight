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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // 1回解いたことある
    // とりあえずn = 3で
    // 0 1 2
    // から逆にやったらできそう
    // ただaiの制限に引っかかりそうで、n = 50に拡張したらいい
    
    ll k;
    cin >> k;
    
    ll loop = k / 50, rest = k % 50;
    
    int n = 50;
    vector<ll> a(n);
    rep(i, n) a[i] = loop + i - rest;
    
    rep(i, rest) a[i] += n + 1;
    
    out(n);
    outa(a, n);
}

