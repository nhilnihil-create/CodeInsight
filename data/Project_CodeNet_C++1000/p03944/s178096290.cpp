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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int w, h, n;
    cin >> w >> h >> n;
    int max_x = 0;
    int min_x = w;
    int max_y = 0;
    int min_y = h;
    rep(i, n) {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1) {
            max_x = max(max_x, x);
        }
        if (a == 2) {
            min_x = min(min_x, x);
        }
        if (a == 3) {
            max_y = max(max_y, y);
        }
        if (a == 4) {
            min_y = min(min_y, y);
        }
    }
    //cout << max_x << " " << min_x << " " << min_y << " " << max_y << endl;
    cout << max(0, min_x - max_x) * max(0, min_y - max_y) << endl;
    return 0;
}
