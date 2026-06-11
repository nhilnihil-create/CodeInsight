#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<vector<int> > tree;

// 頂点 v を根として、p のある側は切り落としてできる部分木について
// v から各頂点への距離を depth に格納する
// (特に p = -1 のときは、ツリー全体について v を根とすることを表す)
void rec(int v, int p, vector<int> &depth) {
    if (p != -1) depth[v] = depth[p] + 1;
    for (auto nv : tree[v]) {
        if (nv == p) continue;
        rec(nv, v, depth);
    }
}

int main() {
    cin >> N >> K;
    tree.assign(N, vector<int>());
    for (int i = 0; i < N-1; ++i) {
        int a, b; cin >> a >> b; --a, --b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int res = N; // INF の気持ち
    vector<int> depth(N);

    if (K % 2 == 0) {
        for (int v = 0; v < N; ++v) {
            depth[v] = 0;
            rec(v, -1, depth);
            int num = 0;
            for (int i = 0; i < N; ++i) if (depth[i] > K/2) ++num;
            res = min(res, num);
        }
    }
    else {
        for (int u = 0; u < N; ++u) {
            for (auto v : tree[u]) {
                int num = 0;

                // u
                depth.assign(N, -1);
                depth[u] = 0;
                rec(u, v, depth);
                for (int i = 0; i < N; ++i) if (depth[i] > K/2) ++num;

                // v
                depth.assign(N, -1);
                depth[v] = 0;
                rec(v, u, depth);
                for (int i = 0; i < N; ++i) if (depth[i] > K/2) ++num;
                
                res = min(res, num);
            }
        }
    }
    cout << res << endl;
}
