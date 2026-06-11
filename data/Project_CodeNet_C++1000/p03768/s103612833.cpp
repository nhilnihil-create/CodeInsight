#include <bits/stdc++.h>
using namespace std;
vector<int> G[100100];
vector<int> color(100100, 0);
vector<int> memo(100100, -10);

void dfs(int v, int d, int c) {
    if(memo[v] >= d) return;
    if(d < 0) return;

    if(!color[v]) color[v] = c;
    memo[v] = d;
    for(int to : G[v]) {
        dfs(to, d - 1, c);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Q;
    cin >> Q;
    vector<int> v(Q), d(Q), c(Q);
    for(int i=Q - 1; i>=0; --i) {
        cin >> v[i] >> d[i] >> c[i];
    }
    
    for(int i=0; i<Q; ++i) {
        dfs(v[i], d[i], c[i]);
    }

    for(int i=1; i<=N; ++i) cout << color[i] << endl;
    return 0;
}