#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    rep(y,ty-sy) cout << "U";
    rep(x,tx-sx) cout << "R";
    rep(y,ty-sy) cout << "D";
    rep(x,tx-sx) cout << "L";
    cout << "L";
    rep(y,ty-sy+1) cout << "U";
    rep(x,tx-sx+1) cout << "R";
    cout << "DR";
    rep(y,ty-sy+1) cout << "D";
    rep(x,tx-sx+1) cout << "L";
    cout << "U" << endl;
    return 0;
}
