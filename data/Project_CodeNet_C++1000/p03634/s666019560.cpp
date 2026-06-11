#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> to;
vector<vector<ll>> cost;

int main() {
	int n;
	cin >> n;
	to.resize(n);
	cost.resize(n);
	rep(i,n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		to[a].push_back(b);
		to[b].push_back(a);
		cost[a].push_back(c);
		cost[b].push_back(c);
	}
	int q, k;
	cin >> q >> k;
	k--;
	vector<int> x(q), y(q);
	rep(i,q) {
	 cin >> x[i] >> y[i];
	 x[i]--, y[i]--;
	}

	vector<ll> dist(n, LINF);
	dist[k] = 0;
	queue<int> que;
	que.push(k);
	while(!que.empty()) {
		int x = que.front(); que.pop();
		for (int j = 0; j < (int) to[x].size(); j++) {
			int nx = to[x][j];
			if (dist[nx] != LINF) continue;
			dist[nx] = dist[x] + cost[x][j];
			que.push(nx);
		}
	}

	rep(i,q) {
		cout << dist[x[i]] + dist[y[i]] << endl;
	}
}