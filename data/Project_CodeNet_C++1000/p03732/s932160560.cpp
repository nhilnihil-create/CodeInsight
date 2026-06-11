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

ll dp[105][110000];
int N;
ll W, w[105], v[105];


int main(void) {
  cin >> N >> W;
  rep(i, 1, N+1) cin >> w[i] >> v[i];
  
  ll w1 = w[1];
  if (w1>1000) {
    rep(i, 1, N+1) w[i] = w[i] - w1 + 1000;
  }
  
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=105000; j++) {
      dp[i][j] = dp[i-1][j];
      if (j-w[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
    }
  }
  
  ll ans = 0;
  for (int wi=1; wi<=105000; wi++) {
    if (w1>1000 && (wi/1000)*w1+wi%1000>W) continue;
    if (w1<=1000 && wi>W) continue;
    
    ans = max(ans, dp[N][wi]);
    
  }
  
  cout << ans << endl;

    return 0;
}

