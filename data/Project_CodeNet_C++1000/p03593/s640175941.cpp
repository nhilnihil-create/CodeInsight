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
#define reprev(i, n) for(ll i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <ll,ll> P;
typedef long double ld;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep (i, h) cin >> s[i];
    vector<int> count(26);
    rep (i, h) rep (j, w) count[s[i][j] - 'a']++;
    int c2 = 0, c1 = 0;
    rep (i, 26) if (count[i] & 2) c2++;
    rep (i, 26) if (count[i] & 1) c1++;
    int m2 = (h % 2 ? w / 2 : 0) + (w % 2 ? h / 2 : 0), m1 = (h % 2) && (w % 2);
    eprintf("c=%d,m=%d c=%d,m=%d\n", c2,m2, c1,m1);
    if ((c2 - m2) % 2 == 0 && c2 <= m2 && c1 == m1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}