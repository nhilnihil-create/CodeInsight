// 5/29
// 2-5-5 わーシャルフロイド
// 類題
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

// 二頂点間の距離を格納する隣接行列
vector<vector<int>> dist;
vector<int> r;

void warshall_floyed(int N) {
    rep(k, N) {
        rep(i, N) {
            rep(j, N) {
                // bool must_visit = false;
                // rep(l, r.size()) {
                //     if(r[l] == k) must_visit = true;
                // }

                // if (must_visit) dist[i][j] = min(INF, dist[i][k] + dist[k][j]);
                // else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N;  // 与えられた有向グラフの頂点の数
    int M;  // 同辺の数（辺の重みは負の場合がある）
    int R;
    cin >> N >> M >> R;

    // vector<int> r(R);
    r.resize(R);
    rep(i, R) {
        cin >> r[i];
        r[i]--;
    }

    dist.assign(N, vector<int>(N, INF));
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        
        // int match = 0;
        // rep(i, R) {
        //     if (a == r[i]) match++;
        //     if (b == r[i]) match++;
        // }
        // if (match == 2) dist[a][b] = dist[b][a] = c;

        dist[a][b] = dist[b][a] = c;
    }

    warshall_floyed(N);

    int ans = INF;
    // // rep(i, N) {
    // //     rep(j, N) {
    // //         ans = min(ans, dist[i][j]);
    // //     }
    // // }
    // rep(i, R) {
    //     rep(j, R) {
    //         ans = min(ans, dist[r[i]][r[j]]);
    //     }
    // }

    sort(r.begin(), r.end());
    do {
        int cost = 0;
        rep(i, R - 1) cost += dist[r[i]][r[i + 1]];
        ans = min(ans, cost);
    } while (next_permutation(r.begin(), r.end()));

    cout << ans << endl;
}
