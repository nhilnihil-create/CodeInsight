
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; cin >> n;
	vi adj[n];
	f(i,0,n-1) {
		int a,b; cin>>a>>b;
		adj[--a].pb(--b); adj[b].pb(a);
	}
	function<int(int,int)> dfs = [&](int v, int p) {
		int ans = 0;
		for (int w : adj[v]) if (w != p)
			ans ^= 1+dfs(w,v);
		return ans;
	};
	cout << (dfs(0,-1)?"Alice":"Bob") << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

