/**
*    created: 16.07.2020 01:58:06
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    auto ctoi = [&] (char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return -1;
    };

    int n, k; cin >> n >> k;
    set<int> st;
    rep(i,k) {int d; cin >> d; st.insert(d);}
    for (int i = n; i <= 10*n+10; i++) {
        string t = to_string(i);
        bool ok = true;
        rep(j,t.size()) {
            int tmp = ctoi(t[j]);
            if (st.count(tmp)) ok = false;
        }
        if (ok) {cout << i << endl; return 0;}
    }
    return 0;
}