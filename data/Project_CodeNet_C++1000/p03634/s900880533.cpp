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

struct edge {
    int from, to, cost;
};

int main (void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<P> > graph(n);
    rep (i, n - 1) {
        int f, t, c; cin >> f >> t >> c; f--; t--;
        graph[f].emplace_back(t, c);
        graph[t].emplace_back(f, c);
    }
    vector<ll> dist(n); rep (i, n) dist[i] = (ll)1e18;
    priority_queue<P, vector<P>, greater<P> > que;
    int q, k; cin >> q >> k; k--;  
    dist[k] = 0; que.push({0, k});
    while (!que.empty()) {
        P p = que.top(); que.pop();
        if (dist[p.second] < p.first) continue;
        for (auto e : graph[p.second]) {
            if (chmin(dist[e.first], dist[p.second] + e.second)) {
                que.emplace(dist[e.first], e.first);
            }
        }
    }
    rep (_, q) {
        int x, y; cin >> x >> y; x--; y--;
        cout << dist[x] + dist[y] << "\n";
    }
    return 0;
}