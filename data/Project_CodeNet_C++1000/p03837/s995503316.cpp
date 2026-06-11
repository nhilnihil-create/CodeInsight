#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX>>4)

int main()
{
    int N, M; cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(N, INF));
    vector<pair<pair<int,int>,int>> ab_c;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = cost[b][a] = c;
        ab_c.emplace_back(make_pair(a, b), c);
    }
    for (int i = 0; i < N; i++) {
        cost[i][i] = 0;
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int ans = 0;
    for (const auto& p : ab_c) {
        int a = p.first.first, b = p.first.second, c = p.second;
        bool including = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (cost[i][j] == cost[i][a] + c + cost[b][j]) {
                    including = true;
                    break;
                } 
            }
            if (including) break;
        }
        if (!including) ans++;
    }

    cout << ans << endl;
}
