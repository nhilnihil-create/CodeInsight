#include <bits/stdc++.h>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 4;
const int inf = (int)1e9;

bool visited[maxn];
vector <int> tpl, tf[maxn];
int dp[maxn], a[maxn];

void cal (int v) {
	int t = 0;
	sort (tf[v].begin(), tf[v].end());
	for (auto u : tf[v]) {
		dp[v] = max (dp[v] + 1, u + 1);
	}
}

void dfs (int v) {
	visited[v] = 1;
	if (!visited[a[v]])
		dfs(a[v]);
	tpl.PB(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = n; i >= 1; i--)
		if (!visited[i])
			dfs(i);
	reverse (tpl.begin(), tpl.end());
	for(auto v : tpl){	
		cal(v);
		tf[a[v]].PB(dp[v]);
	}
	cout << dp[1] << endl;
}
