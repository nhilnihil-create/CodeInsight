#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
vector<int> edge[N];
int col[N];
int a[3];
int n, m;
bool bp;

void DFS(int u) {
    for (int v: edge[u]) {
        if (col[v] != -1) {
            if ((col[v]^col[u]) != 1) bp = false;
        } else {
            col[v] = col[u]^1;
            DFS(v);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(col, -1, sizeof(col));
    for (int i=1; i<=n; ++i) {
        if (col[i] != -1) continue;
        if (edge[i].size() == 0) { col[i] = 0; a[0]++; }
        else {
            col[i] = 0;
            bp = true;
            DFS(i);
            if (bp) a[1]++;
            else a[2]++;
        }
    }
    ll ans = 0;
    for (int i=1; i<3; ++i) {
        for (int j=1; j<3; ++j) {
            if (i == 1 && j == 1) ans += (ll)a[i]*a[j]*2LL;
            else ans += (ll)a[i]*a[j];
        }
    }
    ans += (ll)a[0]*(n-a[0])*2LL+(ll)a[0]*a[0];
    printf("%lld\n", ans);
    return 0;
}
