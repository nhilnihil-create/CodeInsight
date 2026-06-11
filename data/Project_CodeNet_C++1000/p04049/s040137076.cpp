#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
const int Inf = 1000000007;

int n, K;
vector <int> neigh[Maxn];
int L[Maxn], cnt[Maxn];
int dp[Maxn][Maxn];
int res = Inf;

void Traverse(int v, int p)
{
    dp[v][0] = 0;
    L[v] = 0;
    cnt[v] = 1;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        if (u == p) continue;
        Traverse(u, v);
        for (int j = L[v]; j >= 0; j--) {
            int my = dp[v][j]; dp[v][j] = Inf;
            for (int k = 0; k <= L[u]; k++) if (j + k <= K)
                dp[v][max(j, k)] = min(dp[v][max(j, k)], my + dp[u][k]);
        }
        L[v] = max(L[v], L[u]);
        cnt[v] += cnt[u];
    }
    for (int i = 0; i <= L[v] && i <= K; i++)
        res = min(res, dp[v][i] + n - cnt[v]);
    L[v]++;
    for (int i = L[v]; i > 0; i--)
        dp[v][i] = dp[v][i - 1];
    dp[v][0]++;
}

int main()
{
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        neigh[a].push_back(b);
        neigh[b].push_back(a);
    }
    fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
    Traverse(1, 0);
    printf("%d\n", res);
    return 0;
}
