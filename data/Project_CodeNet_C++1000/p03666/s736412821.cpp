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
ll pow(ll a, int b) {return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1;}
ll nck(int n, int k) { ll ret = 1; rep(i, k) {ret *= n - i; ret /= i + 1; } return ret; }
// n <= 60



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    
    rep(k, n + 1) {
        if (k * c - (n - 1 - k) * d <= b - a && b - a <= k * d - (n - 1 - k) * c) {
            out("YES");
            return 0;
        }
    }
    out("NO");
}

