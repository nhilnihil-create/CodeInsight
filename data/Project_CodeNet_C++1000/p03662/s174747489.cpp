#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100005

vector <int> adj[MAX_N];
int dis1[MAX_N];
int dis2[MAX_N];
bool vis1[MAX_N];
bool vis2[MAX_N];

void dfs1(int u)
{
    vis1[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis1[v]) {
            dis1[v] = dis1[u] + 1;
            dfs1(v);
        }
    }
}

void dfs2(int u)
{
    vis2[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis2[v]) {
            dis2[v] = dis2[u] + 1;
            dfs2(v);
        }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    dfs2(n);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
        if (dis1[i] <= dis2[i]) cnt1++;
        else cnt2++;
    }
    if (cnt1 > cnt2) printf("Fennec\n");
    else printf("Snuke\n");
    return 0;
}
