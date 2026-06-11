#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ALL(a) (a).begin(), (a).end()
#define SORT(c) sort(ALL((c)))
#define debug(x)                 \
    do {                         \
        std::cout << #x << ": "; \
        view(x);                 \
    } while (0)

template <typename T>
void view(T e) {
    std::cout << e << std::endl;
}
template <typename T>
void view(const std::vector<T>& v) {
    for (const auto& e : v) {
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}
template <typename T>
void view(const std::vector<std::vector<T>>& vv) {
    for (const auto& v : vv) {
        view(v);
    }
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(M), b(M);
    unordered_map<ll, vector<ll>> m;
    Graph g(N + 1);
    rep(i, M) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<ll> dist(N + 1, LLONG_MAX);
    queue<ll> q;
    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        ll v = q.front();
        q.pop();
        for (auto x : g[v]) {
            if (x == N && (dist[v] + 1) <= 2) {
                puts("POSSIBLE");
                return 0;
            }
            if (dist[x] > dist[v] + 1) {
                dist[x] = dist[v] + 1;
                q.push(x);
            }
        }
    }

    puts("IMPOSSIBLE");

    return 0;
}
