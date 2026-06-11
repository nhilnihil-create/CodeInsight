#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans;
int N, A;
ll x[55], dp[55][2510][55];

int main(void) {
    cin >> N >> A;
    rep(i, 1, N+1) cin >> x[i];

    dp[0][0][0] = 1;
    for (int i=1; i<=N; i++) for (int j=0; j<=2500; j++) for (int k=0; k<=N; k++) {
        dp[i][j][k] += dp[i-1][j][k];
        if (j-x[i]>=0) dp[i][j][k+1] += dp[i-1][j-x[i]][k];
    }

    for (int i=1; i<=50; i++) ans += dp[N][A*i][i];

    cout << ans << "\n";
    return 0;
}

