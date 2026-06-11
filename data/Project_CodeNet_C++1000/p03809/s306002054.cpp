#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

class Graph {
public:
    explicit Graph(int N = 0) : V_NUM(N) { path.resize(V_NUM); }
    void span(int u, int v) { path[u].push_back(v); }
    vector<int> operator[](int v) const { return path[v]; }

    int V_NUM;
    vector<vector<int>> path;
};

void fail() {
    cout << "NO" << endl;
    exit(0);
}

vector<ll> A;
Graph tree;

ll dfs(int v, int r) {
    vector<ll> ch;
    for (int sv : tree[v]) {
        if (sv == r) continue;
        ch.push_back(dfs(sv, v));
    }
    if (ch.empty()) return A[v];

    ll sum = accumulate(ch.begin(), ch.end(), 0LL);
    ll ma = *max_element(ch.begin(), ch.end());

    ll P = min(sum / 2, sum - ma);  // 作れる最大ペア数
    if (A[v] < sum - P || sum < A[v]) fail();

    // 実際に葉同士でペアにするのは、sum-A[v]組
    // よって親に引き継がれる葉の数は、sum-2(sum-A[v])個
    ll ret = A[v] * 2 - sum;
    cerr << v << "," << ret << endl;
    return ret;
}

int main() {
    int N;
    cin >> N;
    A.resize(N);
    for (auto& a : A) cin >> a;

    tree = Graph(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        tree.span(u, v);
        tree.span(v, u);
    }

    // 例外
    if (N == 2) {
        cout << (A[0] == A[1] ? "YES" : "NO") << endl;
        return 0;
    }

    // 葉でない頂点からDFS
    for (int r = 0; r < N; ++r) {
        if (tree[r].size() == 1) continue;
        cout << (dfs(r, -1) == 0 ? "YES" : "NO") << endl;
        return 0;
    }
    terminate();
    return 0;
}
