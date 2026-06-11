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

bool solve() {
    ll n;
    cin >> n;
    
    ll sum = 0;
    vector<ll> a(n);
    for (auto& ai : a) { cin >> ai; sum += ai; }
    ll tmp = n * (n + 1) / 2;
    ll k = sum / tmp;
    if (sum % tmp != 0) return 0;
    
    vector<ll> b(n);
    rep(i, n) { b[i] = a[(i + 1) % n] - a[i]; b[i] -= k; }
    // outa(b, n);
    
    sum = 0;
    rep(i, n) {
        if (b[i] % n == 0 && b[i] < 0) sum += -b[i] / n;
        else if (b[i] != 0) return 0;
    }
    // outa(b, n);
    
    if (sum == k) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    if (solve()) out("YES");
    else out("NO");
}

