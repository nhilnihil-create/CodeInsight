#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;
 
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define y1 abcde
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

const int inf = 2e9;
const int N = 2e3 + 15;
int n, k, sz, cnt, d[N], ans, q[N], ql, qr, d2[N];
vector <int> g[N];

void precalc_dist(int v, int p = -1) {
    for(int to : g[v])
        if(to != p) {
            d[to] = d[v] + 1;
            precalc_dist(to, v);
        }
}

void bfs(int s) {
    fill(d2, d2 + N, inf);
    q[ql = qr = 0] = s;
    d2[s] = cnt = 0;
    while(ql <= qr) {
        int v = q[ql++];
        if(d2[v] > k || d[v] > d[s])
            ++cnt;
        for(int to : g[v])
            if(d2[to] == inf) {
                d2[to] = d2[v] + 1;
                q[++qr] = to;
            }
    }
    ans = min(ans, cnt);
}

void dfs(int v, int p = -1) {
    bfs(v);
    for(int to : g[v])
        if(to != p)
            dfs(to, v);
}

main() {
    cin >> n >> k;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ans = n;
    precalc_dist(1);
    dfs(1);
    cout << ans << endl;
    return 0;
}