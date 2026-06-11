#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL N, K;
	vector<vector<UL>> E;

	UL Loop(UL s, UL t) {
		vector<UL> V(N);
		UL ans = 0;
		queue<pair<UL, UL>> Q;
		Q.push({ s, K }); Q.push({ t, K });
		while (Q.size()) {
			auto p = Q.front(); Q.pop();
			if (V[p.first]) continue;
			V[p.first] = 1; ans++;
			if (p.second == 0) continue;
			for (UL e : E[p.first]) {
				Q.push({ e, p.second - 1 });
			}
		}
		return ans;
	}

	void Solve() {
		cin >> N >> K;
		E.resize(N);
		rep(i, N - 1) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		UL ans = 0;
		if (K % 2) {
			K /= 2;
			rep(i, N) for (UL e : E[i]) if (i < e) ans = max(ans, Loop(i, e));
		}
		else {
			K /= 2;
			rep(i, N) ans = max(ans, Loop(i, i));
		}
		cout << (N - ans) << endl;
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