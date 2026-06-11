#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> /*inline*/ bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> /*inline*/ bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
int MAX_N = 57;
int MAX_SUM = 8000;
int P = 5000;

signed main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= K;
    }
    
    int dp[MAX_N][MAX_SUM] = {0};
    dp[0][P] = 1;
    for (int j = 0; j < N; j++) {
        for (int t = 0; t < MAX_SUM; t++) {
            if (0 <= t + A[j] && t + A[j] < MAX_SUM) {
                dp[j+1][t] = dp[j][t] + dp[j][t+A[j]];
            } else {
                dp[j+1][t] = dp[j][t];
            }
        }
    }
    cout << dp[N][P]-1 << endl;
    return 0;
}