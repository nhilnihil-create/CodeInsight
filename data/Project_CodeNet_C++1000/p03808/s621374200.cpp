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
typedef pair <ll,int> Pll;
typedef long double ld;

ll modll (ll i, ll j) {
    if (i < 0) return (i % j + j) % j;
    else return i % j;
} 
int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n), b(n); rep (i, n) cin >> a[i];
    rep (i, n) b[i] = a[(i + 1) % n] - a[i];
    int k = modll(b[0], n);
    for (ll i : b) {
        if (k != modll(i, n)) {
            cout << "NO\n";
            return 0;
        }
    }

    ll m = b[0]; for (ll i : b) chmax(m, i);
    vector<ll> c(n); rep (i, n) c[i] = (m - b[i]) / n;
    for (ll i : c) eprintf("%lld ", i);
    ll x = 0; rep (i, n) x += (n - i) * c[i];
    eprintf(": %lld ", x);
    ll y = n * (n + 1) / 2LL;
    if (a[0] >= x && (a[0] - x) % y == 0) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}