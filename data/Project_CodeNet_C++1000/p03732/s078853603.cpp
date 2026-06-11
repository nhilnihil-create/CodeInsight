#include<iostream>
#include<iomanip>
#include<cstdio>

#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>

#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

/*
全品の重さがw0からそう離れていない
w0を基準点

dp[i][j]
i個までで重さjになったときの価値の総和の最大値

dp[0][i][j]w0のみ選び個数jになったときの価値の総和

*/
ll dp[4][101][101];

int main() {

    ll N, W; cin >> N >> W;
    vector<ll> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
    for (int k = 0; k <= 3; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= N; j++) {
                dp[k][i+1][j] = dp[k][i][j];
                if (j >= 1) chmax(dp[k][i+1][j],dp[k][i+1][j-1]);
                if (w[i] == w[0]+k && j >= 1) {
                    chmax(dp[k][i+1][j],dp[k][i][j-1]+v[i]);
                }
            }
        }
    }
    ll res = 0;


    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N-i; j++) {
            for (int k = 0; k <= N-i-j; k++) {
                int l = 0, r = N-i-j-k+1;
                ll tmp = W - w[0]*i-(w[0]+1)*j-(w[0]+2)*k;
                if (tmp < 0) continue;
                while (r - l > 1) {
                    int mid = (r+l)/2;
                    if (mid * (w[0]+3) <= tmp) l = mid;
                    else r = mid;
                }
                chmax(res,dp[0][N][i]+dp[1][N][j]+dp[2][N][k]+dp[3][N][l]);
            }
        }
    }
    cout << res << endl;










}
