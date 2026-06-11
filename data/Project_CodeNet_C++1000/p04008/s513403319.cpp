#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<20, mod = 924844033;
int n, k, a[maxn];
int ans = 0;
vi g[maxn];
int dfs(int v = 1) {
	int d = 0;
	for(auto &i : g[v]) d = max(d, 1+dfs(i));
	if(d == k-1 && a[v] != 1) ans++, d = -1;
	return d;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(a[1] != 1) ans++, a[1] = 1;
	for(int i = 2; i <= n; i++) {
		g[a[i]].pb(i);
	}
	dfs();
	cout << ans;
}
