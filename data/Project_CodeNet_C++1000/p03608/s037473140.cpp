#include <iostream>

using namespace std;
using LL = long long;

const LL INF = 1L << 29;

int N, M, R;
int r[8];
bool U[8];
LL d[201][201];
LL ans = INF;

void dfs(int count, int prev, LL dist) {
    if (count == R) {
        ans = min(ans, dist);
        return;
    }
    for (int i = 0; i < R; i++) {
        if (!U[i]) {
            U[i] = true;
            dfs(count + 1, i, prev == -1 ? 0L : dist + d[r[prev]][r[i]]);
            U[i] = false;
        }
    }
}

int main() {

    cin >> N >> M >> R;

    for (int i = 0; i < R; i++) {
        cin >> r[i];
        U[i] = false;
    }

    fill(d[0], d[N + 1], INF);
    for (int i = 1; i <= N; i++) d[i][i] = 0;

    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        d[A][B] = d[B][A] = C;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    dfs(0, -1, 0L);

    cout << ans << endl;
}
