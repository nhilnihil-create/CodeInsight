#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define heap priority_queue
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 100, INF = 1e18; 
string s, ans; 
int n, dp[maxn], nxt[maxn][30], t[maxn]; 

void out() {
	cout << ans; 
	exit(0); 
}

signed main()
{
	cin >> s; 
	n = s.length(); s = ' ' + s; 
	for(int i = n + 1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
			if(i == n + 1) nxt[i][j] = i; 
			else if(s[i+1] - 'a' == j) nxt[i][j] = i + 1; 
			else nxt[i][j] = nxt[i+1][j]; 
		}
		dp[i] = INF; 
	}
	dp[n+1] = 1; 
	for(int i = n; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
			if(dp[i] > dp[nxt[i][j]] + 1) {
				dp[i] = dp[nxt[i][j]] + 1; 
				t[i] = j; 
			}
		}
	}
 	int cur = 0; 
	while(cur < n + 1) {
		cout << char(t[cur] + 'a'); 
		cur = nxt[cur][t[cur]];
	}
}
