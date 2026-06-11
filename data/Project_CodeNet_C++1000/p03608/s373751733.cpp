#include<bits/stdc++.h>
using namespace std;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

const int INF = 1000000001;


signed main() {
    int N, M, R;
    cin >> N >> M >> R;
    int r[R];
    for (int i = 0; i < R; i++) cin >> r[i];
    int A[M], B[M], C[M];
    for (int i = 0; i < M; i++) cin >> A[i] >> B[i] >> C[i];

    for (int i = 0; i < R; i++) r[i]--;
    for (int i = 0; i < M; i++) A[i]--, B[i]--;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (int i = 0; i < M; i++) dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    int ans = INF;
    int ara[R]; for (int i = 0; i < R; i++) ara[i] = i;
    do {
        int sum = 0;
        for (int i = 1; i < R; i++) sum += dist[r[ara[i - 1]]][r[ara[i]]];
        chmin(ans, sum);
    } while (next_permutation(ara, ara + R));

    cout << ans << endl;
    return 0;
}