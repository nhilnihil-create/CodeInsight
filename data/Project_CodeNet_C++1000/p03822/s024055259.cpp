#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
int dp[Maxn];

void Solve(int v)
{
    vector <int> seq;
    for (int i = 0; i < neigh[v].size(); i++) {
        int u = neigh[v][i];
        Solve(u);
        seq.push_back(dp[u]);
    }
    sort(seq.begin(), seq.end());
    for (int i = 0; i < seq.size(); i++)
        dp[v] = max(dp[v], seq[i]) + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int p; scanf("%d", &p);
        neigh[p].push_back(i);
    }
    Solve(1);
    printf("%d\n", dp[1]);
    return 0;
}
