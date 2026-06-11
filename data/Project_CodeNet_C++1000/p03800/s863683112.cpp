#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

int index_check(int cur, int n) {
    if (cur == n) return 0;
    else if (cur == n+1) return 1;
    else return cur;
}

int main(int argc, char const *argv[]) {
    int n;
    string s;
    cin >> n >> s;
    vector<string> dp(4);
    dp[0] = "SS";
    dp[1] = "SW";
    dp[2] = "WS";
    dp[3] = "WW";
    REP(i,4) {
        for (int j = 1; j <= n; ++j) {
            int s_ind = index_check(j, n);
            if (dp[i][j-1] == 'S') {
                if (dp[i][j] == 'S') {
                    if (s[s_ind] == 'o') dp[i].push_back('S');
                    else dp[i].push_back('W');
                }
                else {
                    if (s[s_ind] == 'o') dp[i].push_back('W');
                    else dp[i].push_back('S');
                }
            }
            else {
                if (dp[i][j] == 'S') {
                    if (s[s_ind] == 'o') dp[i].push_back('W');
                    else dp[i].push_back('S');
                }
                else {
                    if (s[s_ind] == 'o') dp[i].push_back('S');
                    else dp[i].push_back('W');
                }
            }
        }
    }
    REP(i,4) {
        string ZO = dp[i].substr(0, 2);
        string NN = dp[i].substr(n, 2);
        //cout << "ZO = " << ZO << " NN = " << NN << endl;
        if (ZO == NN) {
            dp[i].erase(dp[i].begin()+n, dp[i].end());
            cout << dp[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}