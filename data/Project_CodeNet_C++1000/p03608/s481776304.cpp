#include <iostream>
#include <algorithm>
using namespace std;

long long N, M, R, r[211], A[1 << 18], B[1 << 18], C[1 << 18], dist[211][211], minx = (1 << 30);

int main() {
    cin >> N >> M >> R;
    for (int i = 1; i <= R; i++) cin >> r[i];
    for (int i = 1; i <= N; i++) { for (int j = 1; j <= N; j++) dist[i][j] = (1 << 30); dist[i][i] = 0; }
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        dist[A[i]][B[i]] = C[i]; dist[B[i]][A[i]] = C[i];
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
    int G[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    
    do {
        long long sum = 0;
        for (int i = 0; i < R - 1; i++) sum += dist[r[G[i]]][r[G[i + 1]]];
        minx = min(minx, sum);
    } while (next_permutation(G, G + R));
    
    cout << minx << endl;
    return 0;
}
