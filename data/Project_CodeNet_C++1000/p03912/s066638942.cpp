#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_map<int, int>> vm(m, unordered_map<int, int>());
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vm[x % m][x]++;
    }
    vector<pair<int, int>> vp(m, make_pair(0, 0));
    for (int i = 0; i < m; i++) {
        for (auto p : vm[i]) {
            vp[i].first += p.second % 2;
            vp[i].second += p.second / 2 * 2;
        }
    }
    int res = 0;
    res += (vp[0].first + vp[0].second) / 2;
    for (int i = 1; i <= m - i; i++) {
        if (i == m - i) {
            res += (vp[i].first + vp[i].second) / 2;
        } else {
            auto p1 = vp[i], p2 = vp[m - i];
            int r = min(p1.first, p2.first);
            p1.first -= r;
            p2.first -= r;
            res += r;
            if (p1.first > 0) {
                r = min(p1.first, p2.second);
                res += r;
                p2.second -= r;
                res += p1.second / 2;
                res += p2.second / 2;
            } else {
                r = min(p2.first, p1.second);
                res += r;
                p1.second -= r;
                res += p1.second / 2;
                res += p2.second / 2;
            }
        }
    }
    cout << res << endl;
}
