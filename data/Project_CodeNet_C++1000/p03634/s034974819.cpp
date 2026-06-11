#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

struct edge{
	int to;
	ll cost;
};
vector<edge> G[100010];
ll d[100010];
void dfs(int v, int parent) {
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i].to == parent) continue;
		d[G[v][i].to] = d[v] + G[v][i].cost;
		dfs(G[v][i].to, v);
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	int Q, K;
	cin >> Q >> K;
	dfs(K - 1, -1);
	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << d[x] + d[y] << endl;
	}
}