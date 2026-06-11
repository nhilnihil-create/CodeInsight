#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////

struct bellmanford {
	ll N;//頂点数(1-index)
	vector<vector<edge>> g;//有向グラフ
	ll s;


	vector<edge> e;
	vector<ll> ans;//頂点sからiまでの距離(負閉路がない場合)
	ll minuscycle;//sから到達可能な負閉路があるか

	bellmanford(ll N0, ll s0, vector<vector<edge>> g0) {
		N = N0;
		s = s0;
		g = g0;

		ans.assign(N + 1, INF);
		ans[s] = 0;

		repn(i, N) {
			for (edge ed : g[i]) {
				e.push_back(ed);
			}
		}

		minuscycle = 0;

		repn(i, N) {
			for (edge ed : e) {
				if (ans[ed.fr] != INF && ans[ed.fr] + ed.d < ans[ed.to]) {
					ans[ed.to] = ans[ed.fr] + ed.d;
					if (i == N) { minuscycle = 1; }
				}
			}
		}

		}
};

//負の辺のある頂点数Nの有向グラフの頂点sからtまでの距離
ll bell_distance(ll N, ll s, ll t, vector<vector<edge>> g) {

	vector<vector<edge>> rev(N+1);
	repn(v, N) {
		for (edge e : g[v]) {
			rev[e.to].push_back({ e.ind,e.to,e.fr,e.d });
		}
	}

	vector<bool> con(N + 1, 0);
	queue<ll> q;
	con[t] = 1;
	q.push(t);

	while (!q.empty()) {
		ll v = q.front();
		q.pop();

		for (edge e : rev[v]) {
			if (con[e.to] == 1) { continue; }
			con[e.to] = 1;
			q.push(e.to);
		}

	}

	vector<vector<edge>> subg(N + 1);

	repn(v, N) {
		for (edge e : g[v]) {
			if (con[e.fr] == 1 && con[e.to] == 1) { subg[v].push_back(e); }
		}
	}

	bellmanford bf(N, s,subg);

	if (bf.minuscycle == 0) { return bf.ans[t]; }
	else { return -INF; }
}

int main() {
	ll N, M;
	cin >> N >> M;

	vector<vector<edge>> g(N+1);

	repn(i, M) {
		ll a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({ i,a,b,-c });
	}

	ll ans = -bell_distance(N, 1, N, g);

	if (ans == INF) { cout << "inf"; }
	else { cout << ans; }
	system("PAUSE");
}




