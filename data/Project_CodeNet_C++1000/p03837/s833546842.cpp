#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<pair<pii, int>> idist(M);
    Graph<int> dist(N, vector<int>(N, 1e9));
    for (int i = 0; i < N; ++i)
        dist[i][i] = 0;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = dist[b][a] = c;
        idist[i] = {{a, b}, c};
    }

    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        int a = idist[i].first.first;
        int b = idist[i].first.second;
        int c = idist[i].second;
        if (dist[a][b] < c)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
