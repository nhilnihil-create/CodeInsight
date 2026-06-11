#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

constexpr ll INF = 1LL << 62;
constexpr ll MOD = 1e9 + 7;

unordered_map<ll, vector<ll>> G;

void search(ll node, ll d, vector<ll>& dist) {
    if (dist[node] <= d) {
        return;
    }

    dist[node] = d;

    for (auto next : G[node]) {
        search(next, d + 1, dist);
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    for (ll i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<ll> fennec(N + 1, INF);
    search(1, 0, fennec);

    vector<ll> snuke(N + 1, INF);
    search(N, 0, snuke);

    ll fennec_node = 0, snuke_node = 0;
    for (ll i = 1; i <= N; i++) {
        if (fennec[i] <= snuke[i]) {
            fennec_node++;
        } else {
            snuke_node++;
        }
    }

    cout << (fennec_node > snuke_node ? "Fennec" : "Snuke") << endl;

    return 0;
}

