#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const ll INF = 1e18;
const int MAX_V = 1050;
int V, m;
vector<pair<int, ll> > adj[MAX_V];

vl bellmanFord() {
	vl upper(V, INF);
	vi parent(V);
	parent[0] = 0;
	upper[0] = 0;
	for(int iter = 0; iter < V-1; ++iter) {
		for(int here = 0; here < V; ++here) 
			for(int i=0; i<adj[here].size(); ++i) {
				int there = adj[here][i].F;
				ll cost = adj[here][i].S;
				if(upper[there] > upper[here] + cost) {
					upper[there] = upper[here] + cost;
					parent[there] = here;
				}
			}
	}
	vector<bool> path(V, false);
	int here = V-1;
	while(here != 0) {
		if(path[here]) break;
		path[here] = true;
		here = parent[here];
	}
	bool updated = false;
	for(int here = 0; here < V; ++here) {
		for(int i=0; i<adj[here].size(); ++i) {
			int there = adj[here][i].F;
			ll cost = adj[here][i].S;
			if(upper[there] > upper[here] + cost) {
				upper[there] = upper[here] + cost;
				if(path[there]) {
					updated = true;
				}
			}
		}
	}
	if(updated) upper.clear();
	return upper;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> V >> m;
	rep(i,0,m) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		adj[a].pb(mp(b,-c));
	}
	auto ret = bellmanFord();
	if(ret.empty()) {
		cout << "inf" << '\n';
	} else {
		cout << -ret.back() << '\n';
	}
	return 0;
}
