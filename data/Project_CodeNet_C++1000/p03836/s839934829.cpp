#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx;
    int dy = ty - sy;
    rep(i, dx) cout << "R";
    rep(i, dy) cout << "U";
    rep(i, dx) cout << "L";
    rep(i, dy) cout << "D";
    cout << "D";
    rep(i, dx+1) cout << "R";
    rep(i, dy+1) cout << "U";
    cout << "L";
    cout << "U";
    rep(i, dx+1) cout << "L";
    rep(i, dy+1) cout << "D";
    cout << "R";
    cout << endl;
    return 0;
}
