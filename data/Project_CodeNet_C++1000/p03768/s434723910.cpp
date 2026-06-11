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

const int N = 1e5 + 4;
const int D = 11;

pii c[N][D];
int n, m;
vector<int> g[N];

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].em_back(b);
        g[b].em_back(a);
    }
}

void push(int u, int v, int d) {
    int tu = c[u][d].first;
    int tv = c[v][d - 1].first;
    if (tu > tv) {
        c[v][d - 1] = c[u][d];
    }
}

void solve() {
    read();

    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        int v, d, cl;
        cin >> v >> d >> cl;
        c[v][d] = pii(i, cl);
    }

    for (int i = 10; i > 0; --i) {
        for (int u = 1; u <= n; ++u) {
            push(u, u, i);
            for (int to : g[u]) {
                push(u, to, i);
            }
        }
    }

    for (int u = 1; u <= n; ++u) {
        cout << c[u][0].second << "\n";
    }
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
