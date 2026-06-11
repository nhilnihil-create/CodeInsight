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
map <int, map <int, int> > cnt;
main()
{
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int h, w, n;
    cin >> h >> w >> n;
    vector <ll> ans (10);
    vector <pair<int, int> > a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        for (int j = 0; j <= 2; j++) {
            for (int k = 0; k <= 2; k++) {
                if (a[i].x - j > 0 && a[i].y - k > 0 && a[i].x - j + 2 <= h && a[i].y - k + 2 <= w) ++cnt[a[i].x - j][a[i].y - k];
            }
        }
    }
    for (auto &i : cnt) {
        for (auto &j : i.y) {
            ++ans[j.y];
        }
    }
    ll sum = (h - 2ll) * (w - 2ll);
    for (int i = 1; i < 10; i++) sum -= ans[i];
    ans[0] = sum;
    for (int i = 0; i < 10; i++) cout << ans[i] << '\n';
}
