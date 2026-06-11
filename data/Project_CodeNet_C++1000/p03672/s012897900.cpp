/**
*    created: 07.07.2020 00:11:05
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
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int l = s.size() / 2;

    auto check = [&] (string s) {
        int n = s.size()/2;
        bool ok = true;
        rep(i,n) if (s[i] != s[i+n]) ok = false;
        return ok;
    };

    rep2(i,1,l) {
        string t = s.substr(0,s.size()-i*2);
        if (check(t)) {
            cout << t.size() << endl;
            return 0;
        }
    }
    return 0;
}