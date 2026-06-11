#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N - 1) { cin >> A[i + 1]; A[i + 1]--; }
		vector<vector<UL>> E(N);
		for(UL i = 1; i < N; i++) E[A[i]].push_back(i);
		A[0] = N;

		vector<UL> q;
		queue<UL> q2;
		q2.push(0);
		while (q2.size()) {
			auto p = q2.front(); q2.pop();
			q.push_back(p);
			for (UL e : E[p]) q2.push(e);
		}
		reverse(q.begin(), q.end());
		vector<vector<UL>> ans(N + 1);

		rep(i, q.size()) {
			UL p = q[i];
			if (ans[p].size() == 0) { ans[A[p]].push_back(0); continue; }
			sort(ans[p].rbegin(), ans[p].rend());
			UL ansbuf = 0;
			rep(j, ans[p].size()) { ansbuf = max(ansbuf, ans[p][j] + j); }
			ans[A[p]].push_back(ansbuf + 1);
		}

		cout << ans[N][0] << endl;
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
