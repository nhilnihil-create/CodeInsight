#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	struct Node { UL color = 0; UL pri = 0; };

	void Solve() {
		UL N, M, Q; cin >> N >> M;
		vector<Node> G(N);
		vector<vector<UL>> E(N);
		rep(i, M) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		vector<vector<pair<UL, Node>>> q(11);
		cin >> Q;
		rep(i, Q) {
			UL v, d, c; cin >> v >> d >> c;
			v--;
			q[d].push_back({ v, { c, i + 1 } });
		}
		for (auto p : q[10]) {
			if(G[p.first].pri < p.second.pri) G[p.first] = p.second;
		}
		for (UL i = 1; i <= 10; i++) {
			vector<Node> Gbuf = G;
			rep(v, N) {
				for (UL e : E[v]) {
					if (Gbuf[e].pri < G[v].pri) Gbuf[e] = G[v];
				}
			}
			G = move(Gbuf);
			for (auto p : q[10 - i]) {
				if (G[p.first].pri < p.second.pri) G[p.first] = p.second;
			}
		}
		rep(i, N) {
			cout << G[i].color << endl;
		}
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}