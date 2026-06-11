#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

vector<ll> minPath;
vector<vector<pair<ll, ll>>> G;

void dfs (int i) {
    for (ll j = 0; j < G[i].size(); j++) {
        if (minPath[G[i][j].first] == -1) {
            minPath[G[i][j].first] = minPath[i] + G[i][j].second;
            dfs(G[i][j].first);
        }
    }
}

int main() {
    ll N; cin >> N;
    G.resize(N);
    ll a, b, c;
    for (ll i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        a--; b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    ll Q, K; cin >> Q >> K;
    K--;

    minPath.resize(N);
    for (ll i = 0; i < N; i++) minPath[i]--;
    minPath[K] = 0;
    dfs(K);

    ll x, y;
    for (ll i = 0; i < Q; i++) {
        cin >> x >> y;
        x--; y--;
        cout << minPath[x] + minPath[y] << endl;
    }
}
