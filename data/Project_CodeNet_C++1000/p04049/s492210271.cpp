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
const ll M = 998244353;
const ll LLINF = 1000000000000000000;
const double EPS = 1e-8;

#define int long long

vector<vector<int> > tree;
int tmp, k;

void dfs(int v, int prev, int d) {
    if (d > k)
        return;
    ++tmp;
    for (auto u : tree[v]) {
        if (u == prev)
            continue;
        dfs(u, v, d + 2);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t1, t2;
    cin >> n >> k;
    tree.resize(n);
    FOR(i, 0, n - 1) {
        cin >> t1 >> t2;
        --t1; --t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    int ans = n;
    FOR(v, 0, n) {
        tmp = 0;
        dfs(v, v, 0);
        ans = min(ans, n - tmp);
        for (auto u : tree[v]) {
            if (u > v) {
                tmp = 0;
                dfs(v, u, 1);
                dfs(u, v, 1);
                ans = min(ans, n - tmp);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
