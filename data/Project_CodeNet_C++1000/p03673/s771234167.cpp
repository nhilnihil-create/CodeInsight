/**
*    created: 07.07.2020 02:04:58
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

    deque<int> b;
    int n; cin >> n;
    rep(i,n) {
        int a; cin >> a;
        if (i % 2 == 0) b.push_back(a);
        else b.push_front(a);
    }
    if (n % 2 == 0) {
        rep(i,n) {
            int t = b.front(); b.pop_front();
            cout << t << " ";
        }
        cout << endl;
    } 
    else {
        rep(i,n) {
            int t = b.back(); b.pop_back();
            cout << t << " ";
        }
        cout << endl;
    } 
    return 0;
}