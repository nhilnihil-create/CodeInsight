#include <bits/stdc++.h>  

using namespace std;

#define int long long
#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define INF 1e9
#define LINF 1e18

typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> Pi;
typedef pair<P, P> PP;

const int MOD = 1e9 + 7;
const int dy[]={0, 0, 1, -1};
const int dx[]={1, -1, 0, 0};

template <class T> void chmin(T& a, const T& b) { a = min(a, b); }
template <class T> void chmax(T& a, const T& b) { a = max(a, b); }

int n, m;
int x[100000], y[100000];

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    int X = 0, Y = 0;
    rep(i, n) {
        X += x[i] * (i - n + 1 + i);
        X %= MOD;
    }
    rep(i, m) {
        Y += y[i] * (i - m + 1 + i);
        Y %= MOD;
    }
    cout << X * Y % MOD << endl;
    return 0;
}