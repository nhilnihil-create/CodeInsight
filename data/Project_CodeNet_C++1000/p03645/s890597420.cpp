#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;
ll const MAX_V = 200000;

struct edge {
    ll to, cost;
};
vector<edge> G[MAX_V];

int main() {
    ll N, M;
    cin >> N >> M;

    N--;

    for (ll i = 0; i < M; i++) {
        // sからtへの辺を張る
        ll s, t;
        cin >> s >> t;
        s--;
        t--;

        edge et = {t, 1};
        G[s].push_back(et);

        // 無向グラフの場合はさらにtにsへの辺を張る
        edge es = {s, 1};
        G[t].push_back(es);
    }

    for (ll i = 0; i < G[0].size(); i++) {
        vector<edge> n1 = G[G[0][i].to];
        // cout << G[0][i].to << endl;

        for (ll j = 0; j < n1.size(); j++) {
            // cout << n1[j].to << endl;
            if (G[G[0][i].to][j].to == N) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
