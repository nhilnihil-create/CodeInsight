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

#define rep_(i, a_, b_, a, b, ...) for (int i = (a), i##_len = (b); i < i##_len; ++i)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define reprev_(i, a_, b_, a, b, ...) for (int i = (b-1), i##_min = (a); i >= i##_min; --i)
#define reprev(i, ...) reprev_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
// template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    ll ans = 0;
    map<int, int> ma_x, ma_x_mod, ma_mod;
    rep (i, n) {
        int x; cin >> x; ma_x[x]++;
    }
    for (auto p : ma_x) {
        ma_x_mod[p.first % m] += p.second / 2;
        ma_mod[p.first % m] += p.second;
    }
    for (int i = 0; (2 * i) <= m; i++) {
        int j = (m - i) % m;
        if (i == j) {
            ans += ma_mod[i] / 2;
            ma_mod[i] -= (ma_mod[i] / 2) * 2;
        } else {
            int k = min(ma_mod[i], ma_mod[j]);
            ans += k;
            ma_mod[i] -= k; ma_mod[j] -= k;
        }
    }
    eprintf("%lld ", ans);
    rep (i, m) {
        ans += min(ma_x_mod[i], ma_mod[i] / 2);
    }
    cout << ans << "\n";
    return 0;
}