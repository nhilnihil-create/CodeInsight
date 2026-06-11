#include <bits/stdc++.h>

using namespace std;

void chmin(long long &a, long long b) { if (a > b) a = b; }

const auto INF = 1ull << 60u;

vector<long long> a, b, c;
long long dp[51][510][510];

int main() {
    int N;
    long long ma, mb;
    cin >> N >> ma >> mb;

    a.resize(N);
    b.resize(N);
    c.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < 51; ++i) {
        for (int j = 0; j < 510; ++j) {
            for (int k = 0; k < 510; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int wa = 0; wa < 500; ++wa) {
            for (int wb = 0; wb < 500; ++wb) {
                if (dp[i][wa][wb] >= INF) continue;
                chmin(dp[i + 1][wa][wb], dp[i][wa][wb]);
                chmin(dp[i + 1][wa + a[i]][wb + b[i]], dp[i][wa][wb] + c[i]);
            }
        }
    }

    long long ans = INF;
    for (int wa = 1; wa < 500; ++wa) {
        for (int wb = 1; wb < 500; ++wb) {
            if (wa * mb != wb * ma) continue;
            chmin(ans, dp[N][wa][wb]);
        }
    }

    if (ans < INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

