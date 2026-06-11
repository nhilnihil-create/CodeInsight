#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N, K;
vector<vector<int>> edge;

int dfs(int now, int pre, int d, int m) {
    int res = 0;
    if (d > m) res++;
    for (int nxt : edge[now]) {
        if (pre == nxt) continue;
        res += dfs(nxt, now, d+1, m);
    }
    return res;
}

int main() {
    cin >> N >> K;
    edge.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    int ans = N;
    if (K%2 == 0) {
        for (int i = 0; i < N; i++) {
            int cand = dfs(i, -1, 0, K/2);
            ans = min(ans, cand);
        }
        cout << ans << endl;
    }
    if (K%2 == 1) {
        for (int i = 0; i < N; i++) {
            for (int j : edge[i]) {
                if (i < j) continue;
                int cand = dfs(i, j, 0, (K-1)/2) + dfs(j, i, 0, (K-1)/2);
                ans = min(ans, cand);
            }
        }
        cout << ans << endl;
    }
     
    return 0;
}
