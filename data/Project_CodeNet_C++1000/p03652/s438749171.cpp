#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>
#include <functional>

using namespace std;
using ll=long long int;
const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &v: a) for (auto &e: v) {
        cin >> e;
        e--;
    }

    int ans = INF;
    vector<bool> use(m, true);
    for (int t = 0; t < m; ++t) {
        vector<int> cnt(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (use[a[i][j]]) {
                    cnt[a[i][j]]++;
                    break;
                }
            }
        }
        int mi = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        ans = min(ans, cnt[mi]);
        use[mi] = false;
    }

    cout << ans << endl;

    return 0;
}
