#include <bits/stdc++.h>

#define N_MAX 200002

using namespace std;

int n, a, b;

int colorA[N_MAX], colorB[N_MAX];

int cntA, cntB;

vector <int> edgesA[N_MAX], edgesB[N_MAX];

void dfsA (int node, int color)
{
    colorA[node] = color;
    for(int u : edgesA[node])
        if(colorA[u] == 0)
            dfsA(u, color);
}

void dfsB (int node, int color)
{
    colorB[node] = color;
    for(int u : edgesB[node])
        if(colorB[u] == 0)
            dfsB(u, color);
}

map <pair <int, int>, int> mp;

int main()
{
    cin >> n >> a >> b;
    for(int i = 1; i <= a; i++)
    {
        int u, v;
        cin >> u >> v;
        edgesA[u].push_back(v);
        edgesA[v].push_back(u);
    }
    for(int i = 1; i <= b; i++)
    {
        int u, v;
        cin >> u >> v;
        edgesB[u].push_back(v);
        edgesB[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(colorA[i] == 0)
            dfsA(i, ++cntA);
    for(int i = 1; i <= n; i++)
        if(colorB[i] == 0)
            dfsB(i, ++cntB);
    for(int i = 1; i <= n; i++)
        mp[make_pair(colorA[i], colorB[i])]++;
    for(int i = 1; i <= n; i++)
        cout << mp[make_pair(colorA[i], colorB[i])] << " ";
    cout << "\n";
    return 0;
}
