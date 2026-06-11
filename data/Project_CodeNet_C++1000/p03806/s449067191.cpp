#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;

int n, Ma, Mb;
int dp[50][500][500];
vector<int> a(50, 0);
vector<int> b(50, 0);
vector<int> c(50, 0);

int main() {
    cin >> n >> Ma >> Mb;
    int amax = 0; int bmax = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
        amax += a.at(i);
        bmax += b.at(i);
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= amax; ++j) {
            for(int k = 0; k <= bmax; ++k) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= amax; ++j) {
            for(int k = 0; k <= bmax; ++k) {
                chmin(dp[i+1][j+a.at(i)][k+b.at(i)], dp[i][j][k]+c.at(i));
                chmin(dp[i+1][j][k], dp[i][j][k]);
            }
        }
    }

    int ans = INF;
    for(int i = 1; i <= amax; ++i) {
        for(int j = 1; j <= bmax; ++j) {
            if(i % Ma == 0 && j % Mb == 0) {
                if((i / Ma) == (j / Mb)) {
                    chmin(ans, dp[n][i][j]);
                }
            }
        }
    }

    /*for(int i = 0; i <= amax; ++i) {
        for(int j = 0; j <= bmax; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}