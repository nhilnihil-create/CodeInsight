
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

	int n,m; cin>>n>>m;
	vi adj[n];
	bool vis[n];
	f(i,0,m) {
		int a,b; cin>>a>>b;
		adj[--a].pb(--b); adj[b].pb(a);
	}
	f(i,0,n) vis[i] = 0;
	deque<int> dq;	
	f(i,0,n) if (!dq.size() && adj[i].size()) {
		dq.pb(i);	
		vis[i] = 1;
	}
	while (1) {
		int v = dq.back();
		bool found = 0;
		for (int w : adj[v]) if (!found && !vis[w]) {
			vis[w] = 1;
			dq.pb(w);
			found = 1;
		}
		if (!found) break;
	}
	while (1) {
		int v = dq.front();
		bool found = 0;
		for (int w : adj[v]) if (!found && !vis[w]) {
			vis[w] = 1;
			dq.push_front(w);
			found = 1;
		}
		if (!found) break;
	}
	stringstream ss;
	ss << dq.size() << endl;
	for (int v : dq) ss << v+1 << " ";
	cout << ss.str() << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

