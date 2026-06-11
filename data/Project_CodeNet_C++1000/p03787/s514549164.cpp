#include<bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int> > adj;

int cnt, odd;
vector<int> col;
void dfs(int u, int c) {
    cnt++;
    col[u] = c;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(col[v] != -1) {
            if(col[v] == col[u]) odd = 1;
            continue;
        }
        dfs(v, c ^ 1);
    }
}

int a, b, c;
int main() {
    scanf("%d %d", &N, &M);
    adj.resize(N);
    for(int i = 0; i < M; i++) {
        int u, v; scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    col = vector<int>(N, -1);
    a = b = c = 0;
    for(int i = 0; i < N; i++) {
        if(col[i] == -1) {
            cnt = odd = 0;
            dfs(i, 0);
            if(cnt == 1) a++;
            else if(odd) b++;
            else c++;
        }
    }

    long long ans = 0;
    ans += 2LL * a * (N - a) + 1LL * a * a;
    ans += 1LL * b * b;
    ans += 2LL * c * c;
    ans += 2LL * b * c;
    printf("%lld", ans);
}
