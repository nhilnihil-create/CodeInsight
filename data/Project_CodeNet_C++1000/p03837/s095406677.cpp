#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
const int MOD = 1000000007;
const int INF = 1001001001;
using namespace std;

struct Edge {
    int from, to, cost;
    Edge (int from_, int to_, int cost_) {
        from = from_;
        to = to_;
        cost = cost_;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<P>> to(n);
    vector<Edge> e;
    int to_, from, cost;
    rep(i,m) {
        cin >> from >> to_ >> cost;
        from--; to_--;
        to[from].emplace_back(cost, to_);
        to[to_].emplace_back(cost, from);
        e.emplace_back(from, to_, cost);
    }

    int ans = 0;
    for (auto edge: e) {
        // スタート
        int sn = edge.from;
        // スタートからiまでの最小コスト
        vector<int> dp(n, INF);
        dp[sn] = 0;
        // 次に見るノードとこれまでの累計コストを入れる（昇順）
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(0, sn);
        P c;
        while (!pq.empty()) {
            // 累計コストが最も小さいノードに移動
            c = pq.top();
            pq.pop();
            // もし現在のノードのコストが古いもので
            // すでにほかの経路で更新済みだったら次のノードへ移動
            if (dp[c.second] < c.first) continue;
            // 隣接ノードを見る
            for (auto n: to[c.second]) {
                // 最小コストが更新できるか確認
                if (dp[n.second] > dp[c.second] + n.first) {
                    dp[n.second] = dp[c.second] + n.first;
                    // 更新出来たら次に見るノードの候補に入れる
                    pq.emplace(dp[n.second], n.second);
                }
            }
        }

        if (dp[edge.to] < edge.cost) ans++;
    }
    cout << ans << endl;
    return 0;
}