#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pii;

const int N = 2010;

int n, k, dep[N], ans = 0;
Pii A[N];
vector<int> G[N];

int BFS(int a, int b, int k) {
    int res = 0;
    memset(dep, 0, sizeof(dep));
    queue<int> Q; Q.push(a); if(a^b) Q.push(b);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        if(dep[x] <= k) res++;
        int sz = G[x].size();
        for(int i = 0;i < sz; ++i) {
            int u = G[x][i]; if(u == a || u == b) continue;
            if(!dep[u]) {
                dep[u] = dep[x] + 1;
                if(dep[u] <= k) {
                    Q.push(u);
                }
            }
        }
    }
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1, u, v;i < n; ++i) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        A[i] = make_pair(u, v);
    }
    for(int i = 1;i <= n; ++i) {
        ans = max(ans, BFS(i, i, k / 2));
        ans = max(ans, BFS(A[i].first, A[i].second, (k - 1) / 2));
    }
    cout << n - ans << endl;
    return 0;
}