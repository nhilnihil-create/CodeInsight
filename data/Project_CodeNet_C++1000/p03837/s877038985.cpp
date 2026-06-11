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
typedef bitset<1000> B;
typedef pair <int, B > D;
typedef long double ld;

const int INF = 2000000;
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    B bs;
    vector<vector<D> > mat(n, vector<D>(n, make_pair(INF, bs)));
    rep (i, n) {
        mat[i][i] = make_pair(0, bs);
    }
    rep (i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        B tmp;
        tmp.set(i);
        mat[a][b] = mat[b][a] = make_pair(c, tmp);
    }
    rep (k, n) {
        rep (i, n) {
            rep (j, n) {
                if (mat[i][k].first == INF || mat[k][j].first == INF) continue;
                if (chmin(mat[i][j].first, mat[i][k].first + mat[k][j].first)) {
                    mat[i][j].second = mat[i][k].second | mat[k][j].second;
                }
            }
        }
    }
    rep (i, n) {
        rep (j, n) {
            bs |= mat[i][j].second;
        }
    }
    cout << m - bs.count() << "\n";
    return 0;
}