#include <bits/stdc++.h>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define REPV(iter, v) for(auto (iter)=(v).begin(); (iter)!=(v).end();++(iter))
#define ALL(v) (v).begin(),(v).end()

#define MOD 1000000007

using namespace std;

typedef long long ll;

#define MAXN 200
#define INF 1000000000

// WarshallFloyd 法によりグラフにおける任意の2頂点間の最短距離を求める
// n : |V|
// dist : 距離行列

void WarshallFloyd(int n, int dist[MAXN][MAXN])
{
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    REP(i, R)
    {
        cin >> r[i];
        r[i]--;
    }
    sort(ALL(r));
    int dist[MAXN][MAXN];
    REP(i, N) REP(j, N) dist[i][j] = INF;
    REP(i, N) dist[i][i] = 0;
    REP(i, M)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    WarshallFloyd(N, dist);
    int minCost = INT32_MAX;
    do{
        int cost = 0;
        REP(i, R - 1)
        {
            int src = r[i], dst = r[i + 1];
            cost += dist[src][dst];
        } 
        minCost = min(minCost, cost);
    } while(next_permutation(ALL(r)));

    cout << minCost << endl;
}
