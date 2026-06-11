#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
const ll INF = 1e9+100;
const ll MOD = 1e9;
const double EPS = 1e-10;
const bool debug = 0;
//------------------------------//

int N;
int dat[300][300];
ll dp[300][300];

int main() {
	cin >> N;
	REP(i, N) REP(j, N) scanf("%d", &dat[i][j]);
	
	REP(i, N) dp[i][i] = 0;
	REP(i, N) REP(j, N) dp[i][j] = dat[i][j];
	
	REP(k, N) REP(i, N) REP(j, N) chmin(dp[i][j], dp[i][k] + dp[k][j]);
	
	bool ng = false;
	REP(i, N) REP(j, N) if (dat[i][j] != dp[i][j]) ng = true;
	
	if (ng) puts("-1");
	else {
		ll ans = 0;
		
		REP(i, N) FOR(j, i + 1, N) {
			bool f = true;
			REP(k, N) if (k != i && k != j && dp[i][j] == dp[i][k] + dp[k][j]) f = false;
			if (f) ans += dp[i][j];
		}
		cout << ans << endl;
	}
	
	return 0;
}
