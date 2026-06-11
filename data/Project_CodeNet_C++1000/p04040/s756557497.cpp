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
const int MOD = 1e9 + 7;
inline int mul (int a, int b) {
    return ((ll)a * b) % MOD;
}
inline void add (int &a, int x) {
    a += x;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
}
inline int binpow (int a, int n) {
    int ans = 1;
    while (n) {
        if (n & 1) {
            ans = mul(ans, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}
inline int inv (int x) {
    return binpow(x, MOD - 2);
}
const int N = 2e5 + 11;
int f[N] = {}, fi[N] = {};
inline int C (int n, int k) {
    return mul(f[n], mul(fi[k], fi[n - k]));
}
inline int cnt_way (int n, int m) {
    return C(n + m - 2, n - 1);
}
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = mul(f[i - 1], i);
    fi[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        fi[i] = mul(fi[i + 1], i + 1);
    }
    int n, m, a, b, ans = 0;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < n - a; i++) {
        add(ans, mul(cnt_way(i + 1, b), cnt_way(n - i, m - b)));
    }
    cout << ans << '\n';
}
