#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

typedef struct Edge {
    int to, cost;
} Edge;

struct Node {
    ll costK = INT64_MAX;
    vector<Edge> e;
};

void dfs(vector<Node>& NO, int cur, ll cost) {
    for (auto x : NO[cur].e) {
        if (NO[x.to].costK == INT64_MAX) {
            NO[x.to].costK = cost + x.cost;
            dfs(NO, x.to, cost + x.cost);
        }
    }
}

int main() {
    int N; cin >> N;
    vector<Node> NO(N);
    rep (i, N-1) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        NO.at(a).e.emplace_back(Edge{b,c});
        NO.at(b).e.emplace_back(Edge{a,c});
    }

    int Q, K; cin >> Q >> K;
    K--;
    NO[K].costK = 0;
    dfs(NO, K, 0);

    rep(i,Q) {
        int x, y; cin >> x >> y;
        x--, y--;
        cout << NO[x].costK + NO[y].costK << endl;
    }
}
