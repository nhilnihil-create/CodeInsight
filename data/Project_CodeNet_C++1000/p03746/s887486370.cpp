//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define int ll
#define pb push_back
#define bp pop_back
#define X first
#define Y second
#define sz(a) (int)(a.size())

const int MAXN = 1e5 + 10; // ios_base :: sync_with_stdio(false);

signed main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	set<int> adj[MAXN], add[MAXN];
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
		add[a].insert(b);
		add[b].insert(a);
	}
	deque <int> dq;
	int a = 0;
	int b = *adj[0].begin();
	for(int i : adj[a])
		adj[i].erase(a);
	for(int i : adj[b])
		adj[i].erase(b);
	adj[a].erase(b);
	adj[b].erase(a);
	dq.pb(a);
	dq.pb(b);
	while(true) {
		if(sz(adj[dq.back()])) {
			int s = *adj[dq.back()].begin();
//			cout << s << " is in " << dq.back() << endl;
			for(int i : add[s]) {
				adj[i].erase(s);
//				cout << s << " is not in " << i << endl;
			}
			adj[s].erase(dq.back());
			adj[dq.back()].clear();
			dq.push_back(s);
		} else if(sz(adj[dq.front()])) {
			int s = *adj[dq.front()].begin();
//			cout << s << " is in " << dq.front() << endl;
			for(int i : add[s]) {
				adj[i].erase(s);
//				cout << s << " is not in " << i << endl;
			}
			adj[s].erase(dq.front());
			adj[dq.front()].clear();
			dq.push_front(s);	
		} else
			break;
//		for(int i = 0; i < sz(dq); i++)
//			cout << dq[i] << ' ';
//		cout << endl;
	}
	cout << sz(dq) << endl;
	for(int i = 0; i < sz(dq); i++)
		cout << dq[i] + 1 << ' ';
}
