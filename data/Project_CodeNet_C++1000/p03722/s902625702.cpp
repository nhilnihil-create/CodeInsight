#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
const int MOD = 1000000007;
const int INF = 1001001001;
const ll LINF = 9223372036854775807;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    struct Edge {
        int from, to;
        ll cost;
        Edge (int from_, int to_, ll cost_) {
            from = from_;
            to = to_;
            cost = cost_;
        }
    };
    int from, to;
    ll cost;
    vector<Edge> e;
    rep(i,m) {
        cin >> from >> to >> cost;
        from--; to--;
        e.emplace_back(from, to, -cost);
    }

    vector<ll> dp(n,LINF);
    int s = 0;
    dp[s] = 0;

    rep(i,n) {
        rep(j,m) {
            if (dp[e[j].from] == LINF) continue;
            else if (dp[e[j].to] > dp[e[j].from] + e[j].cost) {
                if (e[j].to == n-1 && i == n-1) {
                    cout << "inf" << endl;
                    return 0;
                }
                dp[e[j].to] = dp[e[j].from] + e[j].cost;
            }
        }
    }
    
    cout << -dp[n-1] << endl;
    return 0;
}