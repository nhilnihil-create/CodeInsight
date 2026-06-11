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

int n, m;
const int MAX_N = 100000;
vector<int> g[MAX_N];
int color[MAX_N];

// ある点のcolorが0でないからといってcontinueできない
// その先の頂点は別
// v, dのpairでメモ化
int fin[MAX_N][11];

void dfs(int v, int d, int c) {
    if (fin[v][d]) return;
    fin[v][d] = 1;
    if (d == 0) {
        color[v] = c;
        return;
    }
    dfs(v, d - 1, c);
    for (auto nxt : g[v]) {
        dfs(nxt, d - 1, c);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].eb(b);
        g[b].eb(a);
    }
    
    int q;
    cin >> q;
    
    vector<int> v(q), d(q), c(q);
    rep(i, q) {
        cin >> v[q - 1 - i] >> d[q - 1 - i] >> c[q - 1 - i];
        v[q - 1 - i]--;
    }
    
    rep(i, q) {
        dfs(v[i], d[i], c[i]);
    }
    
    rep(i, n) out(color[i]);
}

