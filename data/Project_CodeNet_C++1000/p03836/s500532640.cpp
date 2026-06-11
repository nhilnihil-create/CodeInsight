#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx-sx;
    int dy = ty-sy;
    
    string ret;
    rep(i, dy) {
        ret += "U";
    }
    rep(i, dx) {
        ret += "R";
    }
    rep(i, dy) {
        ret += "D";
    }
    rep(i, dx+1) {
        ret += "L";
    }
    rep(i, dy+1) {
        ret += "U";
    }
    rep(i, dx+1) {
        ret += "R";
    }
    ret+= "D";
    ret+= "R";
    rep(i, dy+1) {
        ret += "D";
    }
    rep(i, dx+1) {
        ret += "L";
    }
    ret += "U";

    cout << ret << endl;


    return 0;
}

