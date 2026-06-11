#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

int gcd(int m, int n) {
    return n == 0 ? m : gcd(n, m % n);
}
int lcm(int m, int n) {
    return (m / gcd(m, n)) * n;
}

signed main() {
    cin >> H >> W;
    cin >> N;
    vi a(N);
    cin >> a;
    vvi c(H, vi(W));
    int i = 0;
    REP(h, H)
    REP(w, W) {
        if (a[i] == 0)
            i++;
        a[i]--;
        if (h & 1)
            c[h][w] = i + 1;
        else
            c[h][W - w - 1] = i + 1;
    }
    REP(h, H) {
        REP(w, W) {
            cout << c[h][w] << " ";
        }
        cout << endl;
    }
}