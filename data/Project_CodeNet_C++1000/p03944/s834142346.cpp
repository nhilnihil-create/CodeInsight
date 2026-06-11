#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

// 二つの値の最小値を求める関数
Int Min(const Int a, const Int b) {
    if (a <= b) {
        return a;
    } else {
        return b;
    }
}
// 二つの値の最大値を求める関数
Int Max(const Int a, const Int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    Int w, h, n;
    cin >> w >> h >> n;
    Int sx, sy, ex, ey;
    sx = 0;
    sy = 0;
    ex = w;
    ey = h;
    Int x, y, a;
    for (Int i = 0; i < n; ++i) {
        cin >> x >> y >> a;
        if (a == 1) {
            sx = Max(sx, x);
        } else if (a == 2) {
            ex = Min(ex, x);
        } else if (a == 3) {
            sy = Max(sy, y);
        } else if (a == 4) {
            ey = Min(ey, y);
        }
    }
    //cout << sx << " " << ex << " " << sy << " " << ey << endl;
    cout << Max(0, (ex - sx)) * Max(0, (ey - sy)) << endl;
    return 0;
}

