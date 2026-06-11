#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N, W;
    cin >> N >> W;    
    vector<pair<int, int>> wv(N);
    rep(i, N) cin >> wv[i].first >> wv[i].second;
    int wmin = wv[0].first;
    vector<vector<vector<int>>> dp(N);
    int ans = 0;
    
    rep(i, N) {
        wv[i].first -= wmin;
    }
    
    rep(i, N) {
        dp[i].resize(N + 1);
        
        rep(ii, N + 1) {
            dp[i][ii].resize(N * 3, 0);
        }
    }
    
    rep(i, N) {
        if (i == 0) {
            dp[i][1][wv[i].first] = wv[i].second;
            continue;
        }
        
        reps(ii, 1, N + 1) {
            if (ii == 1) {
                rep(iii, N * 3) {
                    if (iii == wv[i].first) {
                        dp[i][ii][iii] = max(dp[i - 1][ii][iii], wv[i].second);
                    }
                    else {
                        dp[i][ii][iii] = dp[i - 1][ii][iii];
                    }
                }
                
                continue;
            }
            
            rep(iii, N * 3) {
                dp[i][ii][iii] = max(dp[i][ii][iii], dp[i - 1][ii][iii]);
                
                if (iii < wv[i].first) {
                    continue;
                }
                
                if (dp[i - 1][ii - 1][iii - wv[i].first] == 0) {
                    continue;
                }
                
                dp[i][ii][iii] = max(dp[i - 1][ii][iii], dp[i - 1][ii - 1][iii - wv[i].first] + wv[i].second);
            }
        }
    }
    
    reps(i, 1, N + 1) {
        rep(ii, N * 3) {
            if (((ll)i * wmin + ii) > (ll)W) {
                continue;
            }
            
            ans = max(ans, dp[N - 1][i][ii]);
        }
    }
    
    cout << ans << endl;
    return 0;
}
