#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
using Graph = vector<vector<pair<ll, ll>>>;


int main()
{
    ll N; cin >> N;
    Graph G(N);
    rep(i, N-1) {
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    ll Q, K; cin >> Q >> K; K--;
    vll X(Q), Y(Q);
    rep(i, Q) {
        cin >> X[i] >> Y[i]; X[i]--, Y[i]--;
    }

    queue<ll> que;
    que.push(K);
    vll dist(N, -1);
    dist[K] = 0;

    while (que.size()) {
        ll node = que.front(); que.pop();

        for (auto e : G[node]) {
            if (dist[e.first] > 0 || e.first == node) continue;
            dist[e.first] = dist[node] + e.second;
            que.push(e.first);
        }
    }

    rep(i, Q) {
        cout << dist[X[i]] + dist[Y[i]] << endl;
    }

    return 0;
}