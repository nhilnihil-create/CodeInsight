//G = G_1 + … + G_kとk個の連結グラフに分け、G_1の頂点番号≦G_2の頂点番号≦…≦G_kの頂点番号となるように番号を振りなおし,
//G_iの頂点番号行, G_jの頂点番号列で一つのブロックを作ると, 異なるブロック間に辺が存在しないので、
//f(G_i, G_j) = 2つの連結グラフG_i, G_jで頂点数|G_i| * |G_j|のグラフを作ったときの連結成分数、とおくとΣf(G_i, G_j)が答えになる。
//
//また、表の行と列を適切に並べ替えても、N^2頂点の表は連結成分数を保ったままなので、番号の振り直しをしなくても↑の議論が成り立つ。
//f(G_i, G_j)の値は（直線グラフや木で実験すると）、G_i, G_jの頂点数がともに2以上のとき2以下になることが分かる。また、
//G_i, G_jの頂点数がともに2以上のとき、共に2部グラフなら(黒, 黒) -- (白, 白)または(黒, 白) -- (白, 黒)としか結べないように表の頂点を彩色できるので、
//連結成分数が2以上(=2)になる。また、どちらか一方でも非2部グラフなら、連結成分数が1になると予想できる。
//((黒,黒)->(黒,白)みたいな辺が存在してしまうため。) また、頂点数がどちらか1なら、辺を張れないので、|Gi| * |Gj|が連結成分数になる。
//
//これよりO(k^2)アルゴリズムは導出できたが、これでは最悪O(N^2)となり間に合わない。
//しかし, 頂点数1の連結成分がx個, 2部グラフの連結成分がy個, 非2部グラフの連結成分がz個あるとすると、x,y,zから答えを求めることができるので、
//O(N)で答えを求めることができる。

#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

struct Edge { int from, to; Edge(int from, int to) { this->from = from; this->to = to; } Edge() { } };
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

int n, m;
Graph g;
vector<Graph> gs;

void labeling() {
	static bool used[100000] = {false};
	static int num[100000];
	queue<int> que;
	int i, j, k;
	
	for (i = 0; i < n; i++) {
		if (used[i]) continue;
		
		vector<int> vs;
		
		used[i] = true; que.push(i); num[i] = 0; vs.push_back(i);
		
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (j = 0; j < g[v].size(); j++) {
				int nv = g[v][j].to;
				if (!used[nv]) {
					used[nv] = true;
					que.push(nv);
					num[nv] = vs.size();
					vs.push_back(nv);
				}
			}
		}
		
		//gs[-]の作成
		Graph gg;
		
		gg.resize(vs.size());
		for (j = 0; j < vs.size(); j++) {
			for (k = 0; k < g[vs[j]].size(); k++) {
				int to = g[vs[j]][k].to;
				gg[j].push_back(Edge(j, num[to]));
			}
		}
		gs.push_back(gg);
	}
}

//連結なグラフが与えられるので、2彩色できるか判定する。
bool isBinary(Graph &g) {
	vector<int> color(g.size());
	queue<int> que;
	int i;
	
	for (i = 0; i < g.size(); i++) color[i] = -1;
	que.push(0);
	color[0] = 0;
	
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (i = 0; i < g[v].size(); i++) {
			int nv = g[v][i].to;
			if (color[nv] == -1) {
				que.push(nv);
				color[nv] = !color[v];
			}
			else if (color[nv] == color[v]) {
				return false;
			}
		}
	}
	return true;
}

signed main() {
	int i;
	
	cin >> n >> m;
	g.resize(n);
	for (i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(Edge(u, v));
		g[v].push_back(Edge(v, u));
	}
	
	labeling();
	
	int x = 0, y = 0, z = 0;
	for (i = 0; i < gs.size(); i++) {
		if (gs[i].size() == 1) x++;
		else if (isBinary(gs[i])) y++;
		else z++;
	}
	
	//cout << x << " " << y << " " << z << endl;
	
	int ans = 2 * x * (n - x) + x * x;
	
	ans += y * y * 2;
	ans += y * z * 1;
	
	ans += z * y * 1;
	ans += z * z * 1;
	cout << ans << endl;
	return 0;
}