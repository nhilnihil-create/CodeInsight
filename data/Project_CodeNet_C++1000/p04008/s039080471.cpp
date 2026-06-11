#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <iterator>
#include <fstream>
#include <math.h>

#include <random>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <list>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

#include <random>
#include <ctime>

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define FOR(i, from, to) for (int i = from; i < to; i++)
#define ROF(i, from, to) for (int i = from; i > to; i--)

const long double PI = 3.141592653589793238463;
const int INF = 0x3f3f3f3f;
const int INFS = 1000000000;
const ll M = 1000000007;
const ll LLINF = 1000000000000000000;
const double EPS = 1e-8;

#define int long long

int ans = 0, k;
vector<vector<int> > tree;
vector<int> mxd, d;

void dfs1(int v, int cd) {
    d[v] = cd;
    mxd[v] = cd;
    for (auto u : tree[v]) {
        dfs1(u, cd + 1);
        mxd[v] = max(mxd[v], mxd[u]);
    }
}

void dfs2(int v, int prev) {
    for (auto u : tree[v])
        dfs2(u, v);
    mxd[v] = d[v];
    for (auto u : tree[v])
        mxd[v] = max(mxd[v], mxd[u]);
    if (prev == 0)
        return;
    if (mxd[v] - d[v] == k - 1) {
        ++ans;
        mxd[v] = d[prev];
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n >> k;
    tree.resize(n);
    mxd.resize(n);
    d.resize(n);
    vector<int> a(n);
    cin >> a[0];
    --a[0];
    if (a[0] != 0)
        ++ans;
    FOR(i, 1, n) {
        cin >> a[i];
        --a[i];
        tree[a[i]].push_back(i);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    cout << ans << "\n";

    return 0;
}
