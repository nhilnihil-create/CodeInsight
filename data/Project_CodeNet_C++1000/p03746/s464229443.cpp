#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		vector<vector<UL>> E(N);
		rep(i, M) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		vector<UL> F(N);
		vector<UL> P1, P2;
		UL p = 0; F[0] = 1;
		while (p != -1) {
			bool ok = false;
			for (UL e : E[p]) {
				if (F[e] == 0) { ok = true; p = e; }
			}
			if (!ok) break;
			P1.push_back(p); F[p] = 1;
		}
		p = 0;
		while (p != -1) {
			bool ok = false;
			for (UL e : E[p]) {
				if (F[e] == 0) { ok = true; p = e; }
			}
			if (!ok) break;
			P2.push_back(p); F[p] = 1;
		}
		reverse(P1.begin(), P1.end());
		cout << (P1.size() + P2.size() + 1) << endl;
		rep(i, P1.size()) { cout << (P1[i] + 1) << " "; }
		cout << 1;
		rep(i, P2.size()) { cout << " " << (P2[i] + 1); }
		cout << endl;
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