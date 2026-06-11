/**
*	created: 11.09.2020 18:56:25
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

signed main() {
    int n, wei; cin >> n >> wei;
    vector<int> w(n), v(n);
    rep(i,n) cin >> w[i] >> v[i];
    deque<int> w1, w2, w3, w4;
    rep(i,n) {
        if (w[i] == w[0]) w1.push_back(v[i]);
        if (w[i] == w[0] + 1) w2.push_back(v[i]);
        if (w[i] == w[0] + 2) w3.push_back(v[i]);
        if (w[i] == w[0] + 3) w4.push_back(v[i]);
    }
    sort(rall(w1)); sort(rall(w2)); sort(rall(w3)); sort(rall(w4));
    w1.push_front(0); w2.push_front(0); w3.push_front(0); w4.push_front(0);
    rep2(i,2,w1.size()) w1[i] += w1[i-1];
    rep2(i,2,w2.size()) w2[i] += w2[i-1];
    rep2(i,2,w3.size()) w3[i] += w3[i-1];
    rep2(i,2,w4.size()) w4[i] += w4[i-1];
    int ans = 0;
    rep(i,w1.size()) rep(j,w2.size()) rep(k,w3.size()) rep(l,w4.size()) {
        int vsum = w1[i] + w2[j] + w3[k] + w4[l];
        int wsum = w[0]*i + (w[0]+1)*j + (w[0]+2)*k + (w[0]+3)*l;
        if (wsum <= wei) chmax(ans,vsum);
    }
    cout << ans << endl;
    return 0;
}
