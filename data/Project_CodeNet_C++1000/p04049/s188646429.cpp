#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2111;

int n, k, a, b;
vector <int> v[N];

int ans;
int siz[N];
int dp[N][N]; // dp[i][j] = ile minimalnie musze usunac zeby srednica byla <= j
int dp2[N];

void dfs(int u, int p) {
	siz[u] = 1;
	rep(i, 0, n) dp[u][i] = 0;
	for (auto it : v[u]) {
		if (it == p) continue;
		dfs(it, u);
		siz[u] += siz[it];
		
		rep(i, 0, n) dp2[i] = n;
		
		rep(ja, 0, n) {
			dp2[ja] = min(dp2[ja], dp[u][ja] + dp[it][min(ja, k - ja)]);
			dp2[ja] = min(dp2[ja], dp[it][ja] + dp[u][min(ja, k - ja)]);
		}
		
		rep(i, 0, n) dp[u][i] = dp2[i];
		rep(i, 1, n) dp[u][i] = min(dp[u][i], dp[u][i - 1]);		
	}
	ans = min(ans, dp[u][k] + (n - siz[u]));
	per(i, 0, n - 1) dp[u][i + 1] = dp[u][i];
	dp[u][0] = siz[u];
}				
		

int main() {		
	scanf ("%d%d", &n, &k);
	rep(i, 1, n - 1) {
		scanf ("%d%d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	ans = n;
	dfs(1, 0);
	printf ("%d\n", ans);
	
	
	return 0;
}
