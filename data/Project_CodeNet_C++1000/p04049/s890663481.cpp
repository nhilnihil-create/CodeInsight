///#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
///#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,mmx,popcnt,avx,avx2,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

/*
    zet:
        find_by_order(k): k-stat [k > 0]
        order_of_key(k) : {el < k}

    gp_hash_table<key, val, custom_hash>

    rope<T>:
        iterators: mutable_begin, ..
        methods  : erase, insert, substr, ..
*/

#define all(x) (x).begin(), (x).end()
#define size(x) (int)((x).size())
#define em_back emplace_back

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<typename T>
using zet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

mt19937 eng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e3 + 4;

int n, k, kv, ke;
vector<int> g[N];

void read() {
    cin >> n >> k;
    kv = k / 2;
    ke = (k - 1) / 2;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].em_back(b);
        g[b].em_back(a);
    }
}

bool used[N];

void dfs(int u, int d, int board) {
    used[u] = 1;
    if (d == board) {
        return;
    }
    for (int to : g[u]) if (!used[to]) {
        dfs(to, d + 1, board);
    }
}

int calcVertex(int u) {
    memset(used, 0, sizeof used);

    used[u]  = 1;
    dfs(u, 0, kv);

    return accumulate(used, used + N, 0);
}

int calcEdge(int u, int v) {
    memset(used, 0, sizeof used);

    used[u] = used[v] = 1;
    dfs(u, 0, ke);
    dfs(v, 0, ke);

    return accumulate(used, used + N, 0);
}

void solve() {
    read();

    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, n - calcVertex(i));
    }
    for (int u = 1; u <= n; ++u) {
        for (int to : g[u]) {
            ans = min(ans, n - calcEdge(u, to));
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);

    int z = 1;
    /// cin >> z;

    while (z--) {
        solve();
    }

    return 0;
}
