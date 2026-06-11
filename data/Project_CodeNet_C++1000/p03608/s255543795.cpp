#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    vec<int> r(R);
    rep(i, R) {
        cin >> r[i];
        --r[i];
    }

    sort(all(r));

    int INF = 1e9+7;
    vec<vec<int>> G(N, vec<int>(N,INF));

    rep(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        --A, --B;
        G[A][B] = C;
        G[B][A] = C;
    }

    rep(i,N) G[i][i] = 0;

    function<void(int)> warshall_floyd = [&](int n) {
        for (int k = 0; k < n; k++) {            // 経由する頂点
            for (int i = 0; i < n; i++) {        // 始点
                for (int j = 0; j < n; j++) {    // 終点
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
    };
    warshall_floyd(N);

    ll ans = INF;
    do {
        ll tmp = 0;
        rep(i, R - 1) {
            tmp += G[r[i]][r[i+1]];
        }
        ans = min(ans,tmp);
    } while (next_permutation(all(r)));


    cout << ans << endl;
}
