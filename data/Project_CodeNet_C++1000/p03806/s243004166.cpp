#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順
#define INF 1<<30

int DP[40+1][401][401];


int main() {
    int N, Ma, Mb; cin >> N >> Ma >> Mb;
    vector<int> A(N), B(N), C(N);
    rep(i,N) {
        int a, b, c; cin >> a >> b >> c;
        A.at(i) = a;
        B.at(i) = b;
        C.at(i) = c;
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= 400; j++)
            for(int k = 0; k <= 400; k++) DP[i][j][k] = INF;
    DP[0][0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int CA = 0; CA <= 400; CA++) {
            for (int CB = 0; CB <= 400; CB++) {
                if (DP[i][CA][CB] == INF) continue;
                // Case 1: Not use #i product
                DP[i+1][CA][CB] = min(DP[i+1][CA][CB], DP[i][CA][CB]);
                // Case 2: Use #i
                DP[i+1][CA+A[i]][CB+B[i]] = min(DP[i+1][CA+A[i]][CB+B[i]], DP[i][CA][CB]+C[i]);
            }
        }
    }

    int ans = INF;
    for (int CA = 1; CA < 401; CA++) {
        for (int CB = 1; CB < 401; CB++) {
            if (CA * Mb == CB * Ma) ans = min(ans, DP[N][CA][CB]);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
