#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 1000000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.push_back(make_pair(x, i));
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i].second % 2 != i % 2;
    }

    cout << ans / 2 << endl;
    return 0;
}