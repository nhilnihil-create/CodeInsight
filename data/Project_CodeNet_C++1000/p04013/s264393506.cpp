#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,A;
    cin >> N >> A;
    vector<int>x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
    }
    int dp[55][55][5000];
    for(int i = 0; i < 55; i++) {
        for(int j = 0; j < 55; j++) {
            for(int k = 0; k < 5000; k++) {
                dp[i][j][k] = 0;
            }
        }
    }
    dp[0][0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < 5000; k++) {
                if(dp[i][j][k] == 0) {
                    continue;
                }
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+x[i]] += dp[i][j][k];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += dp[N][i][i*A];
    }
    cout << ans << endl;
}

