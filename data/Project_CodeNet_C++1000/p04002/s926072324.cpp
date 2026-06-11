#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[] = {1, 0, -1, 0, 0};
const int dy[] = {0, 1, 0, -1, 0};

const int Maxn = 100010;
const int MOD = (int) 1e9 + 7;

ll h, w, n;
map<P, int> mp;
ll ans[10];

void add(int x, int y) {
    for (int i = -2; i <= 0; ++i) {
        for (int j = -2; j <= 0; ++j) {
            int nx = x + i, ny = y + j;
            if (0 <= nx && nx < h - 2 && 0 <= ny && ny < w - 2) {
                mp[P(nx, ny)]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        add(a, b);
    }

    ans[0] = (h - 2) * (w - 2);
    for (auto &m : mp) {
        ans[0]--;
        ans[m.second]++;
    }
    for (int i = 0; i < 10; ++i) {
        cout << ans[i] << endl;
    }

}
