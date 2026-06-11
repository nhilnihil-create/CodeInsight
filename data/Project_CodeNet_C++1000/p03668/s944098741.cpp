#include <cstdio>
#include <vector>
using namespace std;
using Graph = vector< vector<int> >;

int dfs(Graph &G, int cur, int par=-1) {
    int grundy = 0;
    for(auto to : G[cur]) {
        if(to == par) continue;
        grundy ^= dfs(G, to, cur) + 1;
    }
    return grundy;
}

int main() {
    int N; scanf("%d", &N);
    Graph G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    printf("%s\n", dfs(G, 0) ? "Alice" : "Bob");
    return 0;
}