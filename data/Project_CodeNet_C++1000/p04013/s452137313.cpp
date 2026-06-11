#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

long long n, A;
vector<long long> x(55, 0);
long long dp[55][55][3300];

int main() {
    cin >> n >> A;
    for(int i = 0; i < n; ++i) cin >> x.at(i);

    dp[0][0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 0; k < 3300; ++k) {
                dp[i+1][j][k] += dp[i][j][k];
                if(k >= x.at(i)) dp[i+1][j+1][k] += dp[i][j][k-x.at(i)];
            }
        }
    }

    long long ans = 0;
    for(int j = 1; j <= n; ++j) {
        // cout << "j A*j " << j << " " << A*j << " " << dp[n][j][A*j] << endl;
        ans += dp[n][j][A*j];
    }

    cout << ans << endl;
}