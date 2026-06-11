/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;
const int Q_MAX = 100002;
const int D_MAX = 12;

int n, m, q;

vector <int> edges[N_MAX];

struct Query
{
    int u, d, c;
};

Query queries[Q_MAX];

int best[N_MAX][D_MAX];

queue <pair <int, int> > qu;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> q;
    for(int i = 1; i <= q; i++)
        cin >> queries[i].u >> queries[i].d >> queries[i].c;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= 10; j++)
            best[i][j] = -1;
    for(int i = q; i >= 1; i--)
    {
        if(best[queries[i].u][queries[i].d] != -1)
            continue;
        best[queries[i].u][queries[i].d] = i;
        qu.push(make_pair(queries[i].u, queries[i].d));
        while(!qu.empty())
        {
            pair <int, int> f = qu.front();
            qu.pop();
            if(f.second <= 0)
                continue;
            for(int v : edges[f.first])
                if(best[v][f.second - 1] == -1)
                {
                    best[v][f.second - 1] = i;
                    qu.push(make_pair(v, f.second - 1));
                }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int mx = INT_MIN;
        for(int j = 0; j <= 10; j++)
            mx = max(mx, best[i][j]);
        if(mx == INT_MIN)
            cout << "0\n";
        else
            cout << queries[mx].c << "\n";
    }
    return 0;
}
