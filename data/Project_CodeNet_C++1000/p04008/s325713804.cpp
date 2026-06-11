#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n, k;
int a[Maxn];
vector <int> neigh[Maxn];
int ans;

int Traverse(int v, int p)
{
    int res = 0;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        res = max(res, Traverse(u, v));
    }
    res++;
    if (res == k && p != 1) { ans++; return 0; }
    return res;
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    if (a[1] != 1) { ans++; a[1] = 1; }
    for (int i = 2; i <= n; i++)
        neigh[a[i]].push_back(i);
    for (int i = 0; i < neigh[1].size(); i++)
        Traverse(neigh[1][i], 1);
    printf("%d\n", ans);
    return 0;
}
