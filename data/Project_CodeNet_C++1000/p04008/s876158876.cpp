#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int> > G;

using pint = pair<int,int>;
vector<pint> dp;
pint rec(int v, int p) {
    for (auto nv : G[v]) {
        if (nv == p) continue;
        rec(nv, v);
    }
    pint res = {0, 1};
    for (auto nv : G[v]) {
        if (nv == p) continue;
        res.first += dp[nv].first;
        res.second = max(res.second, dp[nv].second + 1);
    }
    if (v != 0 && p != 0 && res.second >= K) ++res.first, res.second = 0;
    return dp[v] = res;
}

int main() {
    cin >> N >> K;
    int res = 0;
    G.clear(); G.resize(N);
    for (int i = 0; i < N; ++i) {
        int a; cin >> a; --a;
        if (i == 0 && a != 0) ++res;
        if (i != 0) {
            G[i].push_back(a);
            G[a].push_back(i);
        }
    }
    dp.assign(N, pint(N, N));
    rec(0, -1);
    cout << res + dp[0].first << endl;
}