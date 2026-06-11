#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edge(N+1, vector<int>());
    int a, b;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<vector<int>> dp(N+1, vector<int>(11, 0));
    int Q;
    cin >> Q;
    vector<int> c(Q+1, 0);
    int v, d;
    for (int i = 1; i <= Q; i++) {
        scanf("%d %d %d", &v, &d, &c[i]);
        dp[v][d] = i;
    }
    for (int i = 9; i >= 0; i--) {
        for (int v = 1; v <= N; v++) {
            dp[v][i] = max(dp[v][i], dp[v][i+1]);
            for (int u : edge[v]) {
                dp[v][i] = max(dp[v][i], dp[u][i+1]);
            }
        }
    }
    for (int v = 1; v <= N; v++) printf("%d\n", c[dp[v][0]]);
    return 0;
}
