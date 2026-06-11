/**
*    author:  souzai32
*    created: 13.08.2020 17:43:53
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    int x,y;
    x=abs(sx-tx); y=abs(sy-ty);

    bool ud=tx<sx,lr=ty<sy;
    string a="UD",b="RL";

    rep(i,x) cout << b.at(lr);
    rep(i,y) cout << a.at(ud);
    rep(i,x) cout << b.at(!lr);
    rep(i,y) cout << a.at(!ud);
    cout << b.at(!lr);
    rep(i,y+1) cout << a.at(ud);
    rep(i,x+1) cout << b.at(lr);
    cout << a.at(!ud);
    cout << b.at(lr);
    rep(i,y+1) cout << a.at(!ud);
    rep(i,x+1) cout << b.at(!lr);
    cout << a.at(ud);

    
    return 0;
}