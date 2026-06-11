#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<vector<UL>> E(N);
		vector<UL> P(N, (UL)-1);
		vector<UL> S;
		rep(i, N - 1) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		queue<UL> Q; Q.push(0);
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			S.push_back(p);
			for (UL e : E[p]) {
				if (P[p] == e) continue;
				P[e] = p;
				Q.push(e);
			}
		}
		vector<vector<UL>> dp(N + 1);
		reverse(S.begin(), S.end());
		P[0] = N;
		rep(i, S.size()) {
			UL p = S[i];
			UL ans = 0;
			UL s = 0; for (UL d : dp[p]) s ^= d;
			ans = s + 1;
			dp[P[p]].push_back(ans);
		}
		if (dp[N][0] == 1) cout << "Bob" << endl;
		else cout << "Alice" << endl;
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