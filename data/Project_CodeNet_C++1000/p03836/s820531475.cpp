#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void output(int diffx, int diffy, int addx, int addy) {
    if (addx) {
        if (diffx > 0) cout << "L";
        else cout << "R";
    }
    if (diffy > 0) rep(i,diffy+addy) cout << "U";
    else rep(i,-diffy+addy) cout << "D";
    if (diffx > 0) rep(i,diffx+addx) cout << "R";
    else rep(i,-diffx+addx) cout << "L";
    if (addy) {
        if (diffy > 0) cout << "D";
        else cout << "U";
    }
}

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int diffx = tx - sx;
    int diffy = ty - sy;
    output(diffx, diffy, 0, 0);
    output(-diffx, -diffy, 0, 0);
    output(diffx, diffy, 1, 1);
    output(-diffx, -diffy, 1, 1);
}

