#include <iostream>
#include <vector>
using namespace std;
void chmin(long long &a, long long b) { if (a > b) a = b; }
const long long INF = 1LL<<60;

int N;
long long ma, mb;
vector<long long> a, b, c;

long long dp[51][510][510];

int main() {
    cin >> N >> ma >> mb;
    a.resize(N); b.resize(N); c.resize(N);
    for (int i = 0; i < N; ++i) cin >> a[i] >> b[i] >> c[i];
    
    for (int i = 0; i < 51; ++i) for (int j = 0; j < 510; ++j) for (int k = 0; k < 510; ++k) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int wa = 0; wa < 500; ++wa) {
            for (int wb = 0; wb < 500; ++wb) {
                if (dp[i][wa][wb] >= INF) continue;
                
                // 使わない
                chmin(dp[i+1][wa][wb], dp[i][wa][wb]);

                // 使う
                chmin(dp[i+1][wa+a[i]][wb+b[i]], dp[i][wa][wb] + c[i]);
            }
        }
    }
    long long res = INF;
    for (int wa = 1; wa < 500; ++wa) {
        for (int wb = 1; wb < 500; ++wb) {
            if (wa * mb != wb * ma) continue;
            chmin(res, dp[N][wa][wb]);
        }
    }
    if (res < INF) cout << res << endl;
    else cout << -1 << endl;
}