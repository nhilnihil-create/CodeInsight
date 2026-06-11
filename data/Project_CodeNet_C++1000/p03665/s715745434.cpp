#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll dp[55][2];

int main() {
    int n, p; cin >> n >> p;
    vector<int> Avec(n, 0);
    for(int i = 0; i < n; ++i) cin >> Avec.at(i);
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 2; ++j) {
            // 袋iを取る
            dp[i+1][(j+Avec.at(i))%2] += dp[i][j];
            
            // 袋iを取らない
            dp[i+1][j] += dp[i][j];
        }
    }

    cout << dp[n][p] << endl;
}