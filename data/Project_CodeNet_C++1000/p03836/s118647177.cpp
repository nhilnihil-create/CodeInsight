#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    string s;
    rep(i, tx - sx) s.push_back('R');
    rep(i, ty - sy) s.push_back('U');
    rep(i, tx - sx) s.push_back('L');
    rep(i, ty - sy) s.push_back('D');
    s.push_back('L');
    rep(i, ty - sy + 1) s.push_back('U');
    rep(i, tx - sx + 1) s.push_back('R');
    s.push_back('D');
    s.push_back('R');
    rep(i, ty - sy + 1) s.push_back('D');
    rep(i, tx - sx + 1) s.push_back('L');
    s.push_back('U');
    cout << s << endl;
}