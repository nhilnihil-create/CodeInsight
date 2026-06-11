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
		vector<ULL> A(N); rep(i, N) cin >> A[i];
		vector<vector<UL>> E(N);
		rep(i, N - 1) {
			UL a, b; cin >> a >> b; a--; b--;
			E[a].push_back(b);
			E[b].push_back(a);
		}
		vector<UL> F(N);
		queue<UL> Q; Q.push(0);
		vector<UL> V;
		vector<UL> P(N);
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			F[p] = 1;
			V.push_back(p);
			for (UL e : E[p]) {
				if (F[e]) continue;
				P[e] = p;
				Q.push(e);
			}
		}
		//rep(i, N) cout << P[i] << " "; cout << endl;
 		reverse(V.begin(), V.end());
		vector<vector<ULL>> dp(N);
		rep(i, V.size() - 1) {
			UL p = V[i];
			//cout << "p = " << p << ",dp[p] = ";
			//for (ULL v : dp[p]) { cout << v << " "; } cout << endl;

			if (E[p].size() == 1) {
				dp[P[p]].push_back(A[p]);
				continue;
			}

			ULL M = 0; ULL S = 0;
			for (ULL v : dp[p]) { M = max(M, v); S += v; }
			if (M > A[p]) { cout << "NO" << endl; return; }
			if (S > A[p] * 2 || A[p] > S) { cout << "NO" << endl; return; }
			dp[P[p]].push_back(A[p] * 2 - S);
		}
		//cout << "p = " << 0 << ",dp[p] = ";
		//rep(i, dp[0].size()) cout << dp[0][i]<< " "; cout << endl;
		ULL S = 0;
		for (ULL v : dp[0]) { S += v; }
		if (E[0].size() == 1) {
			if (S == A[0]) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else {
			if (S == A[0] * 2) cout << "YES" << endl;
			else cout << "NO" << endl;
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
