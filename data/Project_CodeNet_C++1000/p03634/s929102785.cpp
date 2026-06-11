#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
using Graph = vector<vector<pair<int,int>>>;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}

vector<bool> seen;
vector<ll> kyo;
void dfs(const Graph& G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) {
        if (seen[next_v.first]) continue; // next_v が探索済だったらスルー
        kyo[next_v.first] = kyo[v] + next_v.second;
        dfs(G, next_v.first); // 再帰的に探索
    }
}



int main() {

    // 頂点数と辺数
    int N; cin >> N;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < N-1; ++i) {
        int a, b,c;
        cin >> a >> b>>c;
        a--; b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a, c));
    }

    // 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    kyo.assign(N, 0);
    int Q, K;
    cin >> Q >> K;
    K--;
    dfs(G, K);
    vector<ll> x(Q);
    vector<ll> y(Q);
    rep(i, Q) {
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    rep(i, Q) {
        cout << kyo[x[i]] + kyo[y[i]] << endl;
    }
}