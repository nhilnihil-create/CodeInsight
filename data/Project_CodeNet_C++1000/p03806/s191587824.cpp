//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
const int N = 41, X = 11, Y = 11;
int a[N], b[N], c[N], dp[N][N * X][N * Y];
void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N * X; ++j) {
            for (int k = 0; k < N * Y; ++k) {
                dp[i][j][k] = mod;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0][0] = 0;
        for (int j = 0; j < N - a[i]; ++j) {
            for (int k = 0; k < N - b[i]; ++k) {
                if (dp[i][j][k] == mod) continue;
                dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);
                dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
    }
    int ans = mod;
    for (int i = 1; i < N; ++i) ans = min(ans, dp[n][i * x][i * y]);
    if (ans == mod) cout << -1;
    else cout << ans;
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}