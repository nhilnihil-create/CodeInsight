#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    int N, W; cin >> N >> W;
    vector<int> ws(N), vs(N);
    for (int i = 0; i < N; i++) cin >> ws[i] >> vs[i];
    long long w0 = ws[0];
    for (int i = 0; i < N; i++) ws[i] -= w0;
    vector<vector<int>> dp(N * 3 + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int w = i * 3; w >= 0; w--) for (int k = i; k >= 0; k--) {
            chmax(dp[w + ws[i]][k + 1], dp[w][k] + vs[i]);
        }
    }
    int ma = 0;
    for (int w = 0; w <= N * 3; w++) for (int k = 0; k <= N; k++) {
        long long weight = w0 * k + w;
        if (weight > W) continue;
        chmax(ma, dp[w][k]);
    }
    cout << ma << endl;
    return 0;
}