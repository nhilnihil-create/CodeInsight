#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <limits>
#include <climits>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

bool in_bounds(int x, int y, int H, int W)
{
    return (1 <= x && x <= W-2) && (1 <= y && y <= H-2);
}

int main()
{
    ll H, W, N;
    cin >> H >> W >> N;

    unordered_map<int, unordered_map<int, int>> m;

    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        for (int dx = -1; dx <= +1; ++dx) {
            for (int dy = -1; dy <= +1; ++dy) {
                int y = a + dx;
                int x = b + dy;

                if (in_bounds(x, y, H, W)) {
                    m[y][x]++;
                }
            }
        }
    }

    vector<ll> ans(10);
    ll count = 0;
    for (auto&& mm : m) {
        for (auto&& p : mm.second) {
            ans[p.second]++;
            ++count;
        }
    }

    ans[0] = (ll)(W-2)*(H-2) - count;

    for (auto&& ai : ans) {
        cout << ai << endl;
    }

    return 0;
}
