// :)
// "Khodaya, be man "Tagwaye setiz" biamooz ta
//  dar anbuh masuliat nalaghzam ..." -Shariati
#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef pair<int,int> pii;
typedef pair<int64,int> pii32;
typedef pair<int64,int64> pii64;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 2e5+10;
const int64 MO = 1e9+7;
const int64 IN = 1e9;

string s;
int g[maxn][30];
int dp[maxn], nxt[maxn];
int pos[30];
bool vis[maxn];

void dfs (int v) {
	vis[v] = true;
	dp[v] = maxn;
	for (int i = 0; i < 26; i++)
		if (g[v][i] + 1) {
			if (!vis[g[v][i]])
				dfs(g[v][i]);
			if (dp[v] > dp[g[v][i]] + 1) {
				dp[v] = dp[g[v][i]] + 1;
				nxt[v] = i;
			}
		} else {
			dp[v] = 1;
			nxt[v] = i;
			break;
		}
	
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(pos, -1, sizeof pos);
	memset(g, -1, sizeof g);
	cin >> s;
	for (int i = sz(s) - 1; i >= 0; i--) {
		for (int t = 0; t < 26; t++)
			g[i][t] = pos[t];
		pos[s[i] - 'a'] = i;
	}
	int ans = -1;
	for (int i = 0; i < sz(s); i++)
		if (!vis[i])
			dfs(i);
	for (int i = 0; i < 26; i++)
		if (pos[i] + 1) {
			if (ans == -1 || dp[pos[i]] < dp[ans])
				ans = pos[i];
		}
		else
			return cout << (char)(i + 'a') << "\n", 0;
	cout << s[ans];
	while (1) {
		cout << (char)(nxt[ans] + 'a');
		if (g[ans][nxt[ans]] == -1)
			break;	
		ans = g[ans][nxt[ans]];
	} cout << "\n";
}
