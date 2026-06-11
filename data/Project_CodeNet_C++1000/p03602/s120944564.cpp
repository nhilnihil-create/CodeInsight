#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n, 0)), b(n, vector<int>(n, 0));
    rep (i, n) rep (j, n) cin >> a[i][j];
    b = a;
    rep (k, n) rep (i, n) rep (j, n) chmin(b[i][j], b[i][k] + b[k][j]);
    bool wrong = false;
    rep (i, n) rep (j, n) wrong |= (a[i][j] != b[i][j]);
    if (wrong) {
        cout << -1 << "\n";
    } else {
        vector<vector<bool> > use(n, vector<bool>(n, false));
        rep (i, n) rep (j, n) if (i != j) use[i][j] = true;
        rep (i, n) {
            rep (j, n) {
                rep (k, n) {
                    if (i == j || j == k || k == i) continue;
                    if (a[i][j] == a[i][k] + a[k][j]) {
                        use[i][j] = false;
                        break;
                    }
                }
            }
        }
        ll ans = 0;
        rep (i, n) repp (j, i + 1, n) if (use[i][j]) ans += a[i][j];
        cout << ans << "\n";
    }
    return 0;
}