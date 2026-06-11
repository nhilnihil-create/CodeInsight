#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
int64_t INF = 10010010010;
// int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;
// int64_t INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    string res = "";
    rep(i,tx-sx) res += "R";
    rep(i,ty-sy) res += "U";
    rep(i,tx-sx) res += "L";
    rep(i,ty-sy) res += "D";
    res += "D";
    rep(i,tx-sx+1) res += "R";
    rep(i,ty-sy+1) res += "U";
    res += "L";
    res += "U";
    rep(i,tx-sx+1) res += "L";
    rep(i,ty-sy+1) res += "D";
    res += "R";
    cout << res << endl;
}
