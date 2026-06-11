/**
*	created: 24.08.2020 17:55:05
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
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, wei; cin >> n >> wei;
    vector<int> w(n), v(n);
    rep(i,n) cin >> w[i] >> v[i];
    vector<int> w1, w2, w3, w4;
    w1.push_back(INF); w2.push_back(INF); w3.push_back(INF); w4.push_back(INF);
    rep(i,n) {
        if (w[i] == w[0]) w1.push_back(v[i]);
        if (w[i] == w[0] + 1) w2.push_back(v[i]);
        if (w[i] == w[0] + 2) w3.push_back(v[i]);
        if (w[i] == w[0] + 3) w4.push_back(v[i]);
    }
    sort(rall(w1)); sort(rall(w2)); sort(rall(w3)); sort(rall(w4));
    rep2(i,2,w1.size()) w1[i] += w1[i-1];
    rep2(i,2,w2.size()) w2[i] += w2[i-1];
    rep2(i,2,w3.size()) w3[i] += w3[i-1];
    rep2(i,2,w4.size()) w4[i] += w4[i-1];
    int ans = 0;
    rep(i,w1.size()) rep(j,w2.size()) rep(k,w3.size()) rep(l,w4.size()) {
        int vsum = w1[i] + w2[j] + w3[k] + w4[l];
        int wsum = w[0]*i + (w[0]+1)*j + (w[0]+2)*k + (w[0]+3)*l;
        if (w1[i] == INF) vsum -= w1[i];
        if (w2[j] == INF) vsum -= w2[j];
        if (w3[k] == INF) vsum -= w3[k];
        if (w4[l] == INF) vsum -= w4[l];
        if (wsum <= wei) chmax(ans,vsum);
    }
    cout << ans << endl;
    return 0;
}