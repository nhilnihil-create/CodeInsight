#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> A;
vector<vector<int>> edge;

bool dfs(int now, int pre) {
    bool res = true;
    ll cstone = 0;
    ll child = 0;
    ll mx = 0;
    for (int nxt : edge[now]) {
        if (nxt == pre) continue;
        res &= dfs(nxt, now);
        child++;
        cstone += A[nxt];
        mx = max(A[nxt], mx);
    }
    if (child == 0) return true;
    if (child == 1) return (res && (A[now] == cstone));
    if (child >= 2) {
        if (cstone > A[now]*2) res = false;
        if (cstone < A[now]) res = false;
        if (cstone - A[now] > cstone-mx) res = false;
        A[now] -= min(A[now], (cstone - A[now]));
        return res;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    A.resize(N+1, 0);
    edge.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    edge[0].push_back(1);
    edge[1].push_back(0);
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    
    bool ans = dfs(1, 0);
    if (edge[1].size() >= 3 && A[1] != 0) ans = false;
    cout << (ans ? "YES" : "NO") << endl;
    return 0;
}
