#include    <bits/stdc++.h>
#include    <ext/pb_ds/assoc_container.hpp>
#include    <ext/pb_ds/trie_policy.hpp>
#include    <ext/rope>

#pragma     03
#pragma     GCC             optimize("Ofast")
#pragma     GCC             optimization("unroll-loops, no-stack-protector")
#pragma     GCC             target("sse,sse2,sse3,ssse3,sse4.1,sse4.2")

#define     ll              long long
#define     ld              long double
#define     fi              first
#define     se              second
#define     sz(x)           x.size()
#define     mp              make_pair
#define     pb              push_back
#define     eb              emplace_back
#define     all(x)          begin(x), end(x)
#define     rall(x)         rbegin(x), rend(x)
#define     rep(i, x, n)    for (ll i = x; i < n; i++)
#define     fastio()        ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0)
#define     min(a, b)       (a < b) ? a : b
#define     max(a, b)       (a > b) ? a : b
#define     int             long long

using       namespace std;
using       namespace __gnu_pbds;
using       namespace __gnu_cxx;

mt19937     rng(chrono::steady_clock::now().time_since_epoch().count());

typedef     vector<int>     vi;
typedef     vector<vi>      vvi;
typedef     pair<int, int>  ii;
typedef     vector<ii>      vii;
typedef     vector<ll>      vl;
typedef     vector<vl>      vvl;
typedef     pair<ll, ll>    pll;
typedef     vector<pll>     vll;

inline void EXECUTE_TIME() {cout << endl << setprecision(10) << fixed << "CPU Time: " << clock() / double(CLOCKS_PER_SEC) << " sec(s)\n";}

template <class T> inline T RD(T &a) {T x; cin >> x; return a = x;}
template <class T> inline T gcd(T a, T b) {if (b) return gcd(b, a % b); else return a;}
template <class T> inline T lcm(T a, T b) {return a / gcd(a,b) * b;}
template<typename T> using ordered_set=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

const int N = 1e5 + 10;

int a[N];
priority_queue<ii> pq;

signed main() {
//    freopen("bubbletea.inp", "r", stdin);
//    freopen("bubbletea.out", "w", stdout);
    fastio();

    int n; cin >> n;
    int cnt[N], ans[N];
    fill(all(cnt), 1);
    fill(all(ans), 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(mp(a[i], i));
    }

    while (pq.size() > 1) {
        ii x = pq.top(); pq.pop();
        ii y = pq.top(); pq.pop();

        ans[x.se] += cnt[x.se] * (x.fi - y.fi);
        pq.push(mp(y.fi, min(x.se, y.se)));
        cnt[min(x.se, y.se)] += cnt[max(x.se, y.se)];
    }
    ans[0] += n * pq.top().fi;
    rep(i, 0, n) cout << ans[i] << endl;

//    EXECUTE_TIME();
}
