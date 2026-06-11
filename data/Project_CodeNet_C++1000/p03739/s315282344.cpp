#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define int long long
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

signed main() {
    cin >> N;
    vector<int> a(N);
    cin >> a;
    REP(i, N - 1) {
        a[i + 1] = a[i] + a[i + 1];
    }
    if (a[0] < 0) {
        REP(i, N)
        a[i] *= -1;
    }
    dump(a);
    int base = 0;
    if (a[0] == 0) {
        base++;
        ans++;
    }
    REP(i, N) {
        if (i == 0)
            continue;
        if (i & 1) {
            int tmp = (a[i] + base) - (-1);
            if (tmp > 0) {
                ans += tmp;
                base -= tmp;
            }
        } else {
            int tmp = 1 - (a[i] + base);
            if (tmp > 0) {
                ans += tmp;
                base += tmp;
            }
        }
    }
    int hoge = ans;
    ans = 0;
    REP(i, N)
    a[i] *= -1;
    base = 1 - a[0];
    ans += 1 - a[0];
    REP(i, N) {
        if (i == 0)
            continue;
        if (i & 1) {
            int tmp = (a[i] + base) - (-1);
            if (tmp > 0) {
                ans += tmp;
                base -= tmp;
            }
        } else {
            int tmp = 1 - (a[i] + base);
            if (tmp > 0) {
                ans += tmp;
                base += tmp;
            }
        }
    }
    dump(hoge, ans);
    ans = min((ll)hoge, ans);
    cout << ans << endl;
}
