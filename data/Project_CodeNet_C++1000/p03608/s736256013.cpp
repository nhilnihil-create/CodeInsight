#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    vector<int> r(R);
    rep(i, R) cin >> r[i];
    vector<vector<int>> dist(N, vector<int>(N, INF));
    rep(i, N) dist[i][i] = 0;
    rep(i, M) {
        int A, B, C;
        cin >> A >> B >> C;
        dist[A - 1][B - 1] = C;
        dist[B - 1][A - 1] = C;
    }
    
    rep(k, N) rep(i, N) rep(j, N) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
    }
    
    int ans = INF;
    sort(r.begin(), r.end());
    do {
        int cost = 0;
        REP(i, R) cost += dist[r[i - 1] - 1][r[i] - 1];
        ans = min(ans, cost);
    } while (next_permutation(r.begin(), r.end()));
    cout << ans << endl;
    return 0;
}
