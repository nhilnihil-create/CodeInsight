#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<int>> edge(N, vector<int>(N, -1));
    REP(i, N) dist[i][i] = 0;
    REP(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = dist[b][a] = c;
        edge[a][b] = edge[b][a] = c;
    }

    REP(k, N) REP(i, N) REP(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    vector<vector<bool>> used(N, vector<bool>(N));

    REP(i, N) {
        REP(j, N) {
            queue<int> q;
            q.push(j);
            while (!q.empty()) {
                int v = q.front(); q.pop();
                REP(u, N) {
                    if (edge[u][v] != -1 && dist[i][u] + edge[u][v] == dist[i][v]) {
                        used[u][v] = used[v][u] = true;
                        q.push(u);
                    }
                }
            }
        }
    }

    int ans = 0;
    REP(i, N) REP(j, N) if (edge[i][j] != -1 && !used[i][j]) ans++;
    cout << ans / 2 << endl;
}