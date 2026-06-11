#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


void warshall_floyd(int N, vector<vector<int>> &G, int INF) {
    rep(k, N) rep(i, N) {
        if (G[i][k] == INF) continue;
        rep(j, N) {
            if (G[i][j] > G[i][k] + G[k][j]) {
                G[i][j] = G[i][k] + G[k][j];
            }
        }
    }
}


int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R) cin >> r[i];
    rep(i, R) r[i]--;
    sort(r.begin(), r.end());
    int INF = 1 << 30;
    vector<vector<int>> G(N, vector<int>(N, INF));
    int A, B, C;
    rep(i, M) {
        cin >> A >> B >> C;
        A--; B--;
        G[A][B] = C;
        G[B][A] = C;
    }

    warshall_floyd(N, G, INF);

    int cost, ans = INF;
    do {
        cost = 0;
        rep(i, R - 1) cost += G[r[i]][r[i + 1]];
        ans = min(ans, cost);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;

    return 0;
}