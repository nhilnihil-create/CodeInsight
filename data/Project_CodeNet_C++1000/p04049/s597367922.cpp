#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<endl;
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAX = 1010000;
const int MOD = (ll)1000000000 + 7;
const ll INF = 1e17;
const double pi = acos(-1);
const double EPS = 1e-10;

//typedef pair<int, int> P;

const int MAX_V = 2020;
const int MAX_LOG_V = 30;
vector<int> G[MAX_V];
int root;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i] != p)dfs(G[v][i], v, d + 1);
	}
}

void init(int V) {
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < MAX_LOG_V; k++) {
		for (int v = 0; v < V; v++) {
			if (parent[k][v] < 0)parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
		}
	}
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) {
		swap(u, v);
	}
	for (int k = 0; k < MAX_LOG_V; k++) {
		if ((depth[v] - depth[u]) >> k & 1) {
			v = parent[k][v];
		}
	}
	if (u == v)return u;
	for (int k = MAX_LOG_V - 1; k >= 0; k--) {
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	return parent[0][u];
}
int dist(int a, int b) {
	int par = lca(a, b);
	return depth[a] + depth[b] - 2 * depth[par];
}


int N, K;
int A[100010], B[100010];
signed main() {
	cin >> N >> K;
	
	REP(i, N-1) {
		cin >> A[i] >> B[i];
		A[i]--; B[i]--;
		G[A[i]].pb(B[i]);
		G[B[i]].pb(A[i]);
	}
	root = 0;
	init(N);
	int ans = INF;
	if (K % 2 == 0) {
		REP(i, N) {
			int res = 0;
			REP(j, N) {
				if (j == i)continue;
				if (dist(i, j) > K / 2)res++;
			}
			ans = min(ans, res);
		}
	}
	else {
		REP(i, N - 1) {
			int res = 0;
			int l = A[i], r = B[i];
			REP(j, N) {
				if (j == l || j == r)continue;
				int d = min(dist(l, j), dist(r, j));
				if (d > (K - 1) / 2)res++;
			}
			ans = min(ans, res);
		}
	}
	print(ans);
	/*while (true) {
		int x, y; cin >> x >> y;
		pe(depth[x]); print(depth[y]);
		print(lca(x, y));
	}*/
}
