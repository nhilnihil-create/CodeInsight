#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
vi eg[maxn];
int dep[maxn];
void dfs(int a, int fa) {
	for (int i = 0; i < eg[a].size(); i++) {
		int v = eg[a][i];
		if (v == fa) continue;
		dep[v] = dep[a] + 1, dfs(v, a);
	}
}
int u[maxn], v[maxn], mxs = 0;	
int n, k;
int cal(int num) {
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dep[i] <= num) ans++;
	return ans;
}
int main() {

	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u[i], &v[i]), 
		eg[u[i]].pb(v[i]), eg[v[i]].pb(u[i]);
	}
	if (k & 1) {
		for (int i = 1; i < n; i++) {
			dep[u[i]] = dep[v[i]] = 0;
			dfs(u[i], v[i]), 
			dfs(v[i], u[i]);
			mxs = max(mxs, cal(k / 2));
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			dep[i] = 0, dfs(i, 0);
			mxs = max(mxs, cal(k / 2));
		}
	}
	cout << n - mxs << endl;
	return 0;
}
