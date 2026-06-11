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
    #define eprintf(...)
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

// constexpr int MAX = 20;

// vector<vector<int>> grundy(2 * MAX, vector<int>(2 * MAX, -1));
// int mex(vector<int> &v) {
//     if (v.size() == 0) return 0;
//     sort(all(v));
//     if (v.front() > 0) return 0;
//     rep (i, v.size() - 1) {
//         if (v[i + 1] > v[i] + 1) return v[i] + 1;
//     }
//     return v.back() + 1;
// }
// int dfs (int i, int j) {
//     // eprintf("(%d,%d)", i, j);
//     if (i > j) swap(i, j);
//     if (int r = grundy[i][j]; r != -1) return r; 
//     vector<int> v;
//     rep (x, 1, 1 + i / 2) v.push_back(dfs(i - x * 2, j + x));
//     rep (y, 1, 1 + j / 2) v.push_back(dfs(i + y, j - y * 2));
//     return grundy[i][j] = mex(v);
// }

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    // rep (i, MAX) {
    //     rep (j, i + 1) eprintf("%2d ", dfs(i, j));
    //     eprintf("\n");
    // }
    ll x, y; cin >> x >> y;
    cout << (abs(x - y) > 1 ? "Alice\n" : "Brown\n");
    return 0;
}