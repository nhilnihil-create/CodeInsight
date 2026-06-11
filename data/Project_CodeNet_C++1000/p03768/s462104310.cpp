#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 100005;
const int Maxm = 11;

int n, m;
vector <int> neigh[Maxn];
int dist[Maxn][Maxm];
int q;
int qv[Maxn], qd[Maxn], qc[Maxn];
priority_queue <iii> Q;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &qv[i], &qd[i], &qc[i]);
        if (i > dist[qv[i]][qd[i]]) {
            dist[qv[i]][qd[i]] = i;
            Q.push(iii(i, ii(qv[i], qd[i])));
        }
    }
    while (!Q.empty()) {
        ii v = Q.top().second;
        int d = Q.top().first; Q.pop();
        if (dist[v.first][v.second] != d) continue;
        v.second--;
        if (v.second >= 0) {
            ii u = ii(v.first, v.second);
            if (d > dist[u.first][u.second]) {
                dist[u.first][u.second] = d;
                Q.push(iii(d, u));
            }
            for (int i = 0; i < neigh[v.first].size(); i++) {
                u = ii(neigh[v.first][i], v.second);
                if (d > dist[u.first][u.second]) {
                    dist[u.first][u.second] = d;
                    Q.push(iii(d, u));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", qc[dist[i][0]]);
    return 0;
}
