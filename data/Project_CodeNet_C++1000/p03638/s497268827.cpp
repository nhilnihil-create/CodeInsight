/**
*    created: 25.07.2020 07:17:50
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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[8]={0, 1, 0, -1, 1, 1,-1, -1};
const int dy2[8]={1, 0,-1, 0, 1, -1, 1, -1};
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1LL << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h, w; cin >> h >> w;
    int n; cin >> n;
    vector<int> con;
    rep(i,n) {
        int a; cin >> a;
        rep(j,a) con.push_back(i+1);
    }
    vector<vector<int>> v(h,vector<int>(w));
    rep(i,h) rep(j,w) v[i][j] = con[w*i+j];
    rep(i,h) if (i % 2 == 1) reverse(all(v[i]));
    rep(i,h) {
        rep(j,w) {
            if (j == 0) cout << v[i][j];
            else cout << " " << v[i][j];
        }
        cout << endl;
    }
    return 0;
}