#include "bits/stdc++.h"
//#include "ext/pb_ds/assoc_container.hpp"
//#include "ext/pb_ds/tree_policy.hpp"
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int long long
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
#define sz(x) (int)x.size()
const int mod = 1e9 + 7;
//const int mod1 = 998244353;
typedef long double f80;

#ifndef LOCAL
#pragma GCC optimize ("O2")
#define endl '\n'
#endif

//template<typename T>
//using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//int rand(int l, int r){
//    uniform_int_distribution<int> uid(l, r);
//    return uid(rng);
//}

ll pwr(ll a,ll b, ll mod){
    a %= mod;
    ll ans = 1;
    while(b){
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int N = 1e5 + 5;
int x[N];
const int LOGN = 18;
int dp[LOGN][N];

void solve(){
    int n, l, q;
    cin >> n;
    fr(i, 1, n) {
        cin >> x[i];
    }
    cin >> l >> q;
    int pt = 1;
    fr(i, 1, n) {
        while(pt + 1 <= n && x[pt + 1] - x[i] <= l) {
            pt++;
        }
        dp[0][i] = pt;
    }
    for(int i = 1; i < LOGN; i++) {
        fr(j, 1, n) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    fr(i, 1, q) {
        int l, r;
        cin >> l >> r;
        if(l > r) swap(l, r);
        int ans = 0;
        for(int i = LOGN - 1; i >= 0; i--) {
            if(dp[i][l] < r) {
                ans += (1 << i);
                l = dp[i][l];
            }
        }
        ans++;
        cout << ans << endl;
    }
}

signed main(){
    IO;
#ifdef LOCAL
    freopen("inp.txt","r", stdin);
#endif
    cout << setprecision(3) << fixed;
    //    srand(time(NULL));
    //    build();
    int t = 1;
//    cin >> t;
    fr(tt, 1, t){
//        cout << "Case #" << tt << ": ";
        solve();
    }
    return 0;
}
