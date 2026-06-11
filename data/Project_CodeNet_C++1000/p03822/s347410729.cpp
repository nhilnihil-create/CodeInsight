#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e6 + 5);
const int LOG = (int)(20);

int n, dp[N];
vector<int> v[N];

void dfs(int x) {
	int re = 0;
	for(auto i : v[x])
		dfs(i);
	sort(v[x].begin(), v[x].end(), [&] (int a, int b) {
		return dp[a] < dp[b];
	});
	reverse(v[x].begin(), v[x].end());
	for(int i = 0; i < v[x].size(); i++)
		re = max(dp[v[x][i]] + i + 1, re);
	dp[x] = re;
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		v[a].pb(i);
	}
	dfs(1);
	cout << dp[1];
}