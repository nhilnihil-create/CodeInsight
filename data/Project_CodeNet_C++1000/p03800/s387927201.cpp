#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;


int main() {
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> dp(n);
    rep(first, 2) rep(second, 2) {
        dp[0] = first;
        dp[1] = second;
        for (int i = 2; i < n; ++i) {
            if (s[i-1] == 'o') {
                dp[i] = !(dp[i-1]^dp[i-2]);
            } else {
                dp[i] = (dp[i-1]^dp[i-2]);
            }
        }
        if (dp[n-1] ^ (s[n-1] == 'o')) {
            if (dp[n-2] == dp[0]) continue;
        } else {
            if (dp[n-2] != dp[0]) continue;
        }

        if (dp[0] ^ (s[0] == 'o')) {
            if (dp[n-1] == dp[1]) continue;
        } else {
            if (dp[n-1] != dp[1]) continue;
        }

        string ans = "";
        rep(i, n) {
            if (dp[i]) ans += "S";
            else ans += "W";
        }
        cout << ans << endl;
        return 0;

    }

    cout << -1 << endl;


    return 0;
}


    
