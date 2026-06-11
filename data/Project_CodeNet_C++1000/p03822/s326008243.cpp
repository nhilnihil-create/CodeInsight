#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

vector<vector<int>> G;

int dfs(int u) {
    if (G[u].size() == 0) return 0;
    vector<int> S;
    for (int v : G[u]) S.push_back(dfs(v));
    sort(S.rbegin(), S.rend());
    int ans = 0;
    rep(i, S.size()) ans = max(ans, S[i] + i + 1);
    return ans;
}

int main() {
    int N;
    cin >> N;
    G = vector<vector<int>>(N);
    for (int i = 1; i < N; ++i) {
        int a;
        cin >> a;
        --a;
        G[a].push_back(i);
    }
    cout << dfs(0) << "\n";
    return 0;
}
