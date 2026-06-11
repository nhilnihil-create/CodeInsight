#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll dp[55][2];
ll a[55];

int main(){
    int n, p;
    cin >> n >> p;
    rep(i, n) cin >> a[i];

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++){
        if (a[i] % 2 == 0){
            dp[i][0] = 2 * dp[i-1][0];
            dp[i][1] = 2 * dp[i-1][1];
        }
        else {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            dp[i][1] = dp[i-1][1] + dp[i-1][0];
        }
    }

    // rep(i, n) cout << dp[i][0] << " ";
    // cout << endl;
    // rep(i, n) cout << dp[i][1] << " ";
    // cout << endl;    

    cout << dp[n][p] << endl;
    return 0;
}