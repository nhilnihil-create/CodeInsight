#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mod_pow(int x,int y) {
    int res = 1;
    while(y > 0) {
        if(y%2) {
            res = res*x%mod;
        }
        x = x*x%mod;
        y/=2;
    }
    return res;
}
int dp[5005][5005];
signed main() {
    int N;
    string S;
    cin >> N >> S;
    dp[0][0] = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i+1][max(0LL,j-1)] += dp[i][j];
            dp[i+1][j+1] += dp[i][j]*2;
            dp[i+1][max(0LL,j-1)] %= mod;
            dp[i+1][j+1] %= mod;
        }
    }

    cout << dp[N][S.size()]*mod_pow(mod_pow(2,S.size()),mod-2)%mod << endl;
}
