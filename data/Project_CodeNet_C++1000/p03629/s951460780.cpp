#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    string a;
    cin >> a;
    int n = a.size();
    int dp[n + 2];
    fill(dp, dp + n + 2, INF);
    dp[n + 1] = 0;
    int nxt[n + 1][26];
    fill(nxt[0], nxt[n + 1], n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][a[i] - 'a'] = i;
        for (int j = 0; j < 26; j++) {
            dp[i] = min(dp[i], dp[nxt[i][j] + 1] + 1);
        }
    }
    string ans;
    int cur = 0;
    while(cur < n){
        for (int i = 0; i < 26; i++){
            if(dp[cur] == dp[nxt[cur][i] + 1] + 1){
                ans.push_back('a' + i);
                cur = nxt[cur][i] + 1;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}