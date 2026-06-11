#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> Pll;

#define INF 1000000000000000000LL

int main() {
    ll N, M; cin >> N >> M;
    vector<vector<Pll>> G(N+1);
    for (int i = 0; i < M; ++i) {
        ll a, b, c; cin >> a >> b >> c;
        G[a].emplace_back(Pll(b, c));
    }
    vector<ll> cost(N+1, -INF);
    cost[1] = 0;
    bool f = false;
    for (int i = 0; i < N; ++i) {
        f = false;
        for (int j = 1; j <= N; ++j) {
            for (Pll x : G[j]) {
                ll b, c; tie(b, c) = x;
                if (cost[j] + c > cost[b]) {
                    if (b == N) f = true;
                    cost[b] = cost[j] + c;
                }
            }
        }
    }
    if (f) {
        cout << "inf" << endl;
    } else {
        cout << cost[N] << endl;
    }
}
