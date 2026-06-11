#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
#define mod(int)(1000000007)
using namespace std;
const int INF = 1000000000000;
int pre[345678]; //最短路の直前の頂点
int cost[3456][3456]; //cost[u][v]は辺e=(u,v)のコスト(残りINF)
int d[345678]; //頂点sからの最短距離
bool used[345678]; //すでに使われたかのグラフ
void dijkstra(int V, int s) { //頂点数と始点
	fill(d, d + V + 1, INF);
	fill(used, used + V + 1, false);
	fill(pre, pre + V + 1, -1);
	d[s] = 0;
	while (true) {
		int v = -1;
		//まだ使われていない頂点のうちの最小距離を探す
		for (int u = 1; u <= V; u++) {
			if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}
		if (v == -1) break;
		used[v] = true;
		for (int u = 1; u <= V; u++) {
			if (d[u] > d[v] + cost[v][u]) {
				d[u] = d[v] + cost[v][u];
				pre[u] = v;
			}
		}
	}
}
//頂点tへの最短路
vector<int> get_path(int t) {
	vector<int> path;
	for (; t != -1; t = pre[t]) path.push_back(t); //tがsになるまでpre[t]を追う
	//逆順に
	reverse(path.begin(), path.end());
	return path;
}
int cnt[3456][3456], test[345678][2];
signed main() {
	int n, m, a, b, c, ans = 0; cin >> n >> m;
	for (int h = 0; h < 3456; h++) {
		for (int i = 0; i < 3456; i++) {
			cost[h][i] = INF;
		}
	}
	for (int h = 0; h < m; h++) {
		cin >> a >> b >> c;
		test[h][0] = a; test[h][1] = b;
		cost[a][b] = c; cost[b][a] = c;
	}
	for (int h = 1; h < n; h++) {
		for (int i = h + 1; i <= n; i++) {
			dijkstra(n, h); get_path(i);
			for (int j = 0; j < get_path(i).size(); j++) {
				//cout << h << ' ' << i << ' ' << get_path(i)[j] << endl;
				if (j >= 1) {
					cnt[get_path(i)[j - 1]][get_path(i)[j]] = 1;
					cnt[get_path(i)[j]][get_path(i)[j - 1]] = 1;
				}
			}
		}
	}
	for (int h = 0; h < m; h++) {
		if (cnt[test[h][0]][test[h][1]] == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}