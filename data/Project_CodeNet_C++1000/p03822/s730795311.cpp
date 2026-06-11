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

int dfs(int s, const vector<vector<int>> &opp) {
    vector<int> depth;
    for (int t : opp[s]) {
        depth.push_back(dfs(t, opp));
    }

    if (depth.size() == 0)
        return 1;

    sort(depth.rbegin(), depth.rend());

    int ret = -inf;
    for (int i = 0; i < depth.size(); ++i) {
        ret = max(ret, depth[i] + i + 1);
    }

    return ret;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> opp(n);
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        opp[a - 1].push_back(i);
    }

    cout << dfs(0, opp) - 1 << endl;
    return 0;
}