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

const int MAX_N = 100050;
int n, m;
queue<int> adj[MAX_N];

bool isValid(deque<int>& path) {
	int x = path.front();
	int y = path.back();
	return adj[x].empty() && adj[y].empty();
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i,0,m) {
		int a, b;
		cin >> a >> b;
		adj[a].push(b);
		adj[b].push(a);
	}
	deque<int> path;
	vector<bool> vis(n+1);
	vis[1] = true;
	vis[adj[1].front()] = true;
	path.push_back(1);
	path.push_back(adj[1].front());
	adj[1].pop();

	while(!isValid(path)) {
		int x = path.front();
		int y = path.back();
		queue<int>& p = adj[x];
		queue<int>& q = adj[y];
		while(!p.empty()) {
			int f = p.front();
			p.pop();
			if(vis[f]) continue;
			path.push_front(f);
			vis[f] = true;
			break;
		}
		while(!q.empty()) {
			int f = q.front();
			q.pop();
			if(vis[f]) continue;
			path.push_back(f);
			vis[f] = true;
			break;
		}
	}

	cout << path.size() << '\n';
	for(auto it = path.begin(); it != path.end(); ++it) {
		cout << *it << ' ';
	}
	return 0;
}
