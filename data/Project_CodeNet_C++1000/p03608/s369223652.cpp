#include <bits/stdc++.h>
using namespace std;

void warshall_floyd(const int n,
                    vector<vector<int64_t>>& cost) {
    // 辺が存在しない場合は(1LL << 60)で初期化する
    for (auto i = 0; i < n; i++) cost[i][i] = 0;
    for (auto k = 0; k < n; k++) {
        for (auto i = 0; i < n; i++) {
            for (auto j = 0; j < n; j++) {
                // 直接行く場合とkを経由する場合でより小さい距離を採用する
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main(){
    int n, m, r; cin >> n >> m >> r;
    vector<int> v(r); for (auto i = 0; i < r; i++) cin >> v[i], v[i]--;
    vector<vector<int64_t>> cost(n, vector<int64_t>(n, (1LL << 60)));
    for (auto i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        cost[a][b] = c; cost[b][a] = c;
    }
    warshall_floyd(n, cost);
    vector<int> num(r); int64_t ans = INT64_MAX;
    iota(num.begin(), num.end(), 0);
    do {
        int64_t tmp = 0;
        for (auto i = 1; i < (int)num.size(); i++) 
            tmp += cost[v[num[i - 1]]][v[num[i]]];
        ans = min(ans, tmp);
    } while(next_permutation(num.begin(), num.end()));

    cout << ans << endl;
    return 0;
}