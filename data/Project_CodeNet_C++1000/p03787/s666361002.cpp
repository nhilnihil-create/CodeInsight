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

int n, m;

vector <int> edges[N_MAX];

bool visited[N_MAX];

bool color[N_MAX];

bool oddCycle;

int cnt;

void dfs (int u, int last = -1)
{
    visited[u] = true;
    cnt++;
    for(int v : edges[u])
        if(visited[v] == false)
        {
            color[v] = !color[u];
            dfs(v, u);
        }
        else if(color[v] == color[u])
            oddCycle = true;
}

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
    ll cntOdd = 0, cntGraphs = 0, cntSingle = 0;
    for(int i = 1; i <= n; i++)
        if(visited[i] == false)
        {
            oddCycle = false;
            cnt = 0;
            dfs(i);
            if(cnt == 1)
                cntSingle++;
            else if(oddCycle == false)
                cntOdd++;
            else
                cntGraphs++;
        }
    cout << (cntOdd * 2 + cntGraphs) * cntOdd + (cntOdd + cntGraphs) * cntGraphs + cntSingle * n * 2 - cntSingle * cntSingle << "\n";
    return 0;
}
