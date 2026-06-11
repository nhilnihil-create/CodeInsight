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

const int mod = 1e9 + 7;
const int N = 5e3 + 4;

inline int sum(int a, int b) {
    return (a + b) % mod;
}

inline int mult(int a, int b) {
    return (ll)a * b % mod;
}

int n, l;
int c[N][N];
vector<int> dp[N];
int dp2[N][N];

int f2(int num, int len) {
    int& res = dp2[num][len];
    if (res != -1) {
        return res;
    }

    if (num == 0) {
        return res = (len == 1);
    }

    res = 0;
    if (len > 1) {
        res = sum(res, f2(num - 1, len - 1));
    }
    res = sum(res, mult(2, f2(num - 1, len + 1)));

    return res;
}

int f(int num, int len) {
    int& res = dp[len][num];
    if (res != -1) {
        return res;
    }

    if (len > num) {
        return res = 0;
    }
    if (len == num) {
        return res = 1;
    }
    res = 0;

    if (len == 1) {
        return res = f2(num - 1, 1);
    }

    for (int k = 1; k < num; ++k) {
        res = sum(res, mult(dp[len >> 1][k], dp[(len + 1) >> 1][num - k]));
    }

    return res;
}

void prepare() {
    c[0][0] = 1;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            if (j == 0) {
                c[i][j] = sum(c[i - 1][j], c[i - 1][j + 1]);
            } else {
                c[i][j] = sum(mult(2, c[i - 1][j - 1]), c[i - 1][j + 1]);
            }
        }
    }
    memset(dp2, -1, sizeof dp2);

    vector<int> lres;
    vector<int> q;
    q.em_back(l);
    while (size(q)) {
        vector<int> nq;
        for (int u : q) {
            if (u != 1) {
                nq.em_back(u / 2);
                nq.em_back((u + 1) / 2);
            }
            lres.em_back(u);
        }
        sort(all(nq));
        nq.erase(unique(all(nq)), nq.end());
        q = nq;
    }

    sort(all(lres));
    lres.erase(unique(all(lres)), lres.end());
    for (int u : lres) {
        dp[u].resize(n + 1, -1);
        for (int i = 0; i <= n; ++i) {
            f(i, u);
        }
    }
}

void calc() {
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans = sum(ans, mult(c[i][0], f(n - i, l)));
    }
    cout << ans << "\n";
}

void solve() {
    string s;
    cin >> n >> s;
    l = size(s);

    prepare();
    calc();
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
