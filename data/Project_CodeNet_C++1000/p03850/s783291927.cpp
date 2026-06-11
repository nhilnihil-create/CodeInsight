#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> P;

const ll INF = 1ll<<60;
const ll MOD = 1000000007;
const double EPS  = 1e-10;

int n;
ll a[112345];
string op[112345];
ll dp[112345][3];

int main() {
	cin >> n;
	cin >> a[0]; op[0] = "+";
	REP(i, n - 1) cin >> op[i + 1] >> a[i + 1];
	
	fill(dp[0], dp[n + 1], -INF);
	dp[0][0] = 0;
	
	REP(i, n) {
		REP(j, 3) {
			if (dp[i][j] == -INF) continue;
			
			REP(k, 3) {
				int nextj = j - k;
				if (nextj < 0) continue;
				
				if (op[i] == "-") {
					if (nextj == 2) nextj = 1;
					else nextj++;
				}
				
				chmax(dp[i + 1][nextj], dp[i][j] + a[i] * (nextj & 1 ? -1 : 1));
			}
		}
	}
	
	
	ll ans = -INF;
	REP(i, 3) chmax(ans, dp[n][i]);
	cout << ans << endl;
	
	return 0;
}