/**
*    created: 09.07.2020 01:11:05
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

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> p;
    vector<pair<int,int>> c;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        p.push_back(make_pair(a,b));
    }
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        c.push_back(make_pair(a,b));
    }
    rep(i,n) {
        int x = p[i].first;
        int y = p[i].second;
        int ret;
        int d = INF;
        rep(j,m) {
            int a = c[j].first;
            int b = c[j].second;
            if (abs(x-a) + abs(y-b) < d) {
                ret = j+1;
                d = abs(x-a) + abs(y-b);
            }
        }
        cout << ret << endl;
    }
    return 0;
}