#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll dp[51][51][2505];

int main() {
    int N; cin >> N;
    int A; cin >> A;
    vector<int> x(N);
    rep(i, N){
        cin >> x[i];
    }

    for (int i = 0; i <= N; i++){
        dp[i][0][0] = 1;
    }

    for (int i = 0; i < N; i++){
        for (int j = 1; j <= i+1; j++){
            for (int k = 0; k < 2505; k++){
                if(k < x[i]){
                    dp[i+1][j][k] = dp[i][j][k];
                } else {
                    dp[i+1][j][k] = dp[i][j][k] + dp[i][j-1][k-x[i]];
                }
            }
        }
    }

    ll ans = 0;
    for (int j = 1; j <= N; j++){
        ans += dp[N][j][A*j];
    }

    cout << ans << endl;

    return 0;
}