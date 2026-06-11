#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


#define MAX_V 120000

struct edge { int to, cost; }; //cost >= 0

int V, E, r; //頂点数、辺数、始点
vector<edge>G[MAX_V]; //グラフ情報
int d[MAX_V]; //最短距離

void dijkstra() { //始点rから各頂点への最短距離を求める
	priority_queue<P, vector<P>, greater<P>>q; //小さい順に取り出す(確定した頂点を見るから)
	fill(d, d + V, INF); //初期化
	d[r] = 0; //始点から始点までの距離は0
	q.push(P(0, r)); //firstは最短距離、secondは頂点の番号

	while (!q.empty()) {
		P p = q.top();
		q.pop();
		int v = p.second; //今見ている頂点番号
		if (d[v] < p.first)continue;
		for (int i = 0; i < G[v].size(); i++) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) { //頂点e.toまでの最短距離よりも、頂点vを経由する経路の距離のほうが短かったら
				d[e.to] = d[v] + e.cost; //更新
				q.push(P(d[e.to], e.to));
			}
		}
	}
}

signed main() {
	cin >> V;
	rep(i, V - 1) {
		int s, t, d;
		edge e;
		cin >> s >> t >> d;
		s--; t--;
		e.to = t;
		e.cost = d;
		G[s].push_back(e);
		e.to = s;
		G[t].push_back(e);
	}
	int Q;
	cin >> Q >> r;
	r--;
	dijkstra();
	vector<int>ans(Q);
	rep(i, Q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		ans[i] = d[x] + d[y];
	}
	rep(i, Q)cout << ans[i] << endl;
}