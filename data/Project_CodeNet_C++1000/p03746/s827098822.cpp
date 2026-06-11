#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
Graph G;
vector<int> used, ans_front, ans_back;

void dfs_front(int u) {
    used[u] = 1;
    for (auto e : G[u]) {
        if (!used[e.to]) {
            ans_front.push_back(e.to);
            dfs_front(e.to);
            break;
        }
    }
}

void dfs_back(int v) {
    used[v] = 1;
    for (auto e : G[v]) {
        if (!used[e.to]) {
            ans_back.push_back(e.to);
            dfs_back(e.to);
            break;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    G = Graph(N);
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        --A;
        --B;
        G[A].push_back({B});
        G[B].push_back({A});
    }
    
    used = vector<int>(N, 0);
    int u = 0;
    int v = G[0][0].to;
    ans_front.push_back(0);
    ans_back.push_back(v);
    used[0] = used[v] = 1;
    dfs_front(u);
    dfs_back(v);
    reverse(ans_front.begin(), ans_front.end());
    cout << ans_front.size() + ans_back.size() << endl;
    rep(i, ans_front.size()) cout << ans_front[i] + 1 << endl;
    rep(i, ans_back.size()) cout << ans_back[i] + 1 << endl;
    return 0;
}
