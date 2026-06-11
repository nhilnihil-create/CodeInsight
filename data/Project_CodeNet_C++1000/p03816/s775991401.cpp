/**
*    created: 30.07.2020 22:24:40
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if (b < a) {a = b; return 1;} return 0;}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[8] = {0, 1, 0, -1, 1, 1,-1, -1};
const int dy2[8] = {1, 0,-1, 0, 1, -1, 1, -1};
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    map<int,int> mp;
    rep(i,n) {int a; cin >> a; mp[a]++;}
    int dcnt = 0;
    for (auto p : mp) if (p.second >= 2) {
        int t = p.second;
        while (t >= 3) t = t % 3 + t / 3;
        if (t >= 2) dcnt++;
    }
    if (dcnt % 2 == 0) cout << mp.size() << endl;
    else cout << mp.size() - 1 << endl;
}