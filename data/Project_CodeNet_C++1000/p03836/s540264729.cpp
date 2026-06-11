#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int64_t i=0; i<(int64_t)(n); i++)
#define all(v) v.begin(), v.end()

int main(){

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    rep(i, tx-sx) cout << "R";
    rep(i, ty-sy+1) cout << "U";
    rep(i, tx-sx+1) cout << "L";
    rep(i, ty-sy+1) cout << "D";
    cout << "RD" ;
    rep(i, tx-sx+1) cout << "R";
    rep(i, ty-sy+1) cout << "U";
    rep(i, tx-sx+1) cout << "L";
    rep(i, ty-sy) cout << "D";
    
    return 0;
}