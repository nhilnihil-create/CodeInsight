#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    int xd = abs(tx-sx);
    int yd = abs(ty-sy);
    rep(i, xd){
        cout << "R";
    }
    rep(i, yd){
        cout << "U";
    }
    rep(i, xd){
        cout << "L";
    }
    rep(i, yd){
        cout << "D";
    }
    cout << "D";
    rep(i, xd+1){
        cout << "R";
    }
    rep(i, yd+1){
        cout << "U";
    }
    cout << "L";
    cout << "U";
    rep(i, xd+1){
        cout << "L";
    }
    rep(i, yd+1){
        cout << "D";
    }
    cout << "R" << endl;

    return 0;
}