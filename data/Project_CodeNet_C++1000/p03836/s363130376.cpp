#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    string res;
    int dx = tx-sx, dy = ty-sy;
    rep(i, dx)res.push_back('R');
    rep(i, dy)res.push_back('U');
    rep(i, dx)res.push_back('L');
    rep(i, dy)res.push_back('D');
    res.push_back('D'); 
    rep(i, dx+1)res.push_back('R');
    rep(i, dy+1)res.push_back('U');
    res.push_back('L');
    res.push_back('U');
    rep(i, dx+1)res.push_back('L');
    rep(i, dy+1)res.push_back('D');
    res.push_back('R');
    cout << res << ln;
}
