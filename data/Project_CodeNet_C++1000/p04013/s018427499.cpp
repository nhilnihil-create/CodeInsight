#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep1(i, n) for(int i=1; i<=n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define rrep1(i, n) for(int i=n; i>=1; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, a, x[55];
ll dp[55][5050];

int main() {
    cin >> n >> a;
    rep(i, n) cin >> x[i];

    int M = a;
    rep(i, n) chmax(M, x[i]);

    rep(i, n) x[i] -= a;
    dp[0][n*M] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 2*n*M; j++) {
            if (j - x[i] < 0 || j - x[i] > 2*n*M) {
                dp[i+1][j] = dp[i][j];
            } else {
                dp[i+1][j] = dp[i][j] + dp[i][j-x[i]];
            }
        }
    }
    cout << dp[n][n*M] - 1 << endl;
}
