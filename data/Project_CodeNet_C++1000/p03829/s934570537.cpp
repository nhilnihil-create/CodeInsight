/**
*	created: 29.09.2020 20:10:31
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define len(x) ll(x.size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
using ll = long long;
using P = pair<int,int>;
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (b < a) {a = b; return 1;} return 0;}
inline void print(P a) {cout << a.first << " " << a.second << endl;}
template<typename T> T bpow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

signed main() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    int st = v[0];
    sort(all(v));
    int l = v[0], r = v[n-1];
    vector<int> d(n-1);
    rep(i,n-1) d[i] = v[i+1] - v[i];
    // 1 -> 左端 -> 右端
    int sum1 = min((st-l) * a, b);
    rep(i,n-1) sum1 += min(a*d[i],b);
    // 1 -> 右端 -> 左端
    int sum2 = min((r-st) * a, b);
    rep(i,n-1) sum2 += min(a*d[i],b);
    cout << min(sum1,sum2) << endl;
    return 0;
}