#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
//#define int long long
#define pb push_back
#define x first
#define ld long double
#define y second
#define mk(a,b) make_pair(a,b)
#define rr return 0
#define sqr(a) ((a)*(a))
#define all(a) a.begin(),a.end()

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class value, class cmp = less<value> >
using ordered_set = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class value, class cmp = less_equal<value> >
using ordered_multiset = tree<value, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = less<key> >
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

/// find_by_order()
/// order_of_key()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int randll(int l = INT_MIN, int r = INT_MAX) {
    return uniform_int_distribution<int>(l, r)(rng);
}
const int N = 5001, MOD = 1e9 + 7;
int dp[N][N][2] = {}, ok[N][N][2] = {};
inline void add (int &val, int x) {
    val += x;
    if (val >= MOD) val -= MOD;
    if (val < 0) val += MOD;
}
inline int mul (int a, int b) {
    return ((ll)a * b) % MOD;
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    ok[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k < 2; k++) {
                if (!ok[i][j][k]) continue;
                add(ok[i + 1][j + 1][k], mul(ok[i][j][k], 2));
                add(ok[i + 1][max(0, j - 1)][k | (j == 0)], ok[i][j][k]);
            }
        }
    }
    int k = (int)s.length();
    int ans = (ok[n][k][0] + ok[n][k][1]) % MOD;
    for (int i = 0; i < k; i++) ans = mul(ans, 500000004);
    cout << ans << '\n';
}
