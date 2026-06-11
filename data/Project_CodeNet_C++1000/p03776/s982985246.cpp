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
#define fls(x) (64 - __builtin_clzll(x))
#define pcnt(x) __builtin_popcountll(x)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, a, b; cin >> n >> a >> b;
    vector<ll> v(n); rep (i, n) cin >> v[i];
    sort(all(v), greater<ll>());
    ll sum = 0, ka = 0, kb = 0, k = 0;
    rep (i, a) sum += v[i];
    rep (i, n) {
        if (v[i] == v[a - 1]) {
            if (i < a) ka++;
            else kb++;
            k++;
        }
    }
    chmin(kb, (ll)b - a);
    printf("%.6lf\n", (double)sum / a);
    eprintf("%lld %lld %lld\n", ka, ka + kb, k);

    vector<vector<ll>> com(n + 1, vector<ll>(n + 1));
    com[0][0] = 1;
    rep (i, n + 1) {
        rep (j, n + 1) {
            if (i > 0) com[i][j] += com[i - 1][j];
            if (j > 0) com[i][j] += com[i][j - 1];
            if (i < 10 && j < 10) eprintf("%5lld ", com[i][j]);
        }
        if (i < 10) eprintf("\n");
    }
    ll ans = 0;
    if (v[a - 1] == v[0]) rep (i, ka, ka + kb + 1) ans += com[k - i][i];
    else ans = com[k - ka][ka];
    printf("%lld\n", ans);
    return 0;
}