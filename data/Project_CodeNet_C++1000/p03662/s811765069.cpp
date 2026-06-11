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

struct UnionFind {
    vector< int > data;
    UnionFind(int sz) {
        data.assign(sz, -1);
    }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }
    int find(int k) {
        if(data[k] < 0) return (k);
        return (data[k] = find(data[k]));
    }
    int size(int k) {
        return (-data[find(k)]);
    }
};


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> g[100000];
    rep (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // BFS
    vector<int> dist(n), prev(n);
    repp (i, 1, n) dist[i] = -1;
    prev[0] = -1;
    priority_queue<P> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        P p = q.top(); q.pop();
        for (int i : g[p.second]) {
            if (dist[i] == -1) {
                dist[i] = p.first + 1;
                prev[i] = p.second;
                q.emplace(dist[i], i);
            }
        }
    }
    vector<int> dist_snuke(n), prev_snuke(n);
    rep (i, n - 1) dist_snuke[i] = -1;
    prev_snuke[n - 1] = -1;
    priority_queue<P> q_snuke;
    q_snuke.emplace(0, n - 1);
    while (!q_snuke.empty()) {
        P p = q_snuke.top(); q_snuke.pop();
        for (int i : g[p.second]) {
            if (dist_snuke[i] == -1) {
                dist_snuke[i] = p.first + 1;
                prev_snuke[i] = p.second;
                q_snuke.emplace(dist_snuke[i], i);
            }
        }
    }

    // backtrace
    vector<int> route;
    int now = n - 1;
    while (now != 0) {
        route.push_back(now);
        now = prev[now];
    }
    route.push_back(0);
    reverse(all(route));
    rep (i, route.size()) eprintf("%d ", route[i]); eprintf("\n");

    // union-find
    UnionFind uf(n);
    repp (i, 1, route.size()) {
        if (i != (route.size() + 1) / 2) uf.unite(route[i], route[i - 1]);
    }
    rep (i, n) {
        if (prev[i] == prev_snuke[i]) uf.unite(i, prev[i]);
    }
    rep (i, n) eprintf("%d ", prev[i]); eprintf("\n");
    rep (i, n) eprintf("%d ", prev_snuke[i]); eprintf("\n");
    rep (i, n) eprintf("%d ", uf.find(i)); eprintf("\n");
    eprintf("%d %d\n", uf.size(0), uf.size(n - 1));
    cout << (uf.size(0) > uf.size(n - 1) ? "Fennec\n" : "Snuke\n");
    return 0;
}