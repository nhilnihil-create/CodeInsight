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
    int n;
    cin >> n;
    vector<int> color(9, 0);
    rep(i, n) {
        int a;
        cin >> a;
        if (a < 400) {
            ++color[0];
        }
        else if (a < 800) {
            ++color[1];
        }
        else if (a < 1200) {
            ++color[2];
        }
        else if (a < 1600) {
            ++color[3];
        }
        else if (a < 2000) {
            ++color[4];
        }
        else if (a < 2400) {
            ++color[5];
        }
        else if (a < 2800) {
            ++color[6];
        }
        else if (a < 3200) {
            ++color[7];
        }
        else {
            ++color[8];
        }
    }
    int ans = 0;
    rep(i, 8) {
        if (color[i]) ++ans;
    }
    if (ans == 0) {
        cout << 1 << " ";
    }
    else {
        cout << ans << " ";
    }
    cout << ans + color[8] << endl;
    return 0;
}