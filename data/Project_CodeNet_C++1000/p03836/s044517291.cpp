#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 998244353;


int main() {
    int sx, sy, tx, ty; 
    cin >> sx >> sy >> tx >> ty;

    int dx = tx - sx;
    int dy = ty - sy;

    string ret = "";
    rep(i, dy) ret += "U";
    rep(i, dx) ret += "R";
    rep(i, dy) ret += "D";
    rep(i, dx) ret += "L";
    ret += "L";
    rep(i, dy+1) ret += "U";
    rep(i, dx+1) ret += "R";
    ret += "D";
    ret += "R";
    rep(i, dy+1) ret += "D";
    rep(i, dx+1) ret += "L";
    ret += "U";
    cout << ret << endl;
    return 0;
}