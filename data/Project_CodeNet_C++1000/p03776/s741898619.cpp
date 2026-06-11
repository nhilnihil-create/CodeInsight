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
		UL A, B; cin >> A >> B;
		vector<ULL> V(N); rep(i, N) cin >> V[i];
		sort(V.rbegin(), V.rend());
		if (V[0] == V[A - 1]) {
			cout << V[0] << endl;
			UL M = A;
			while (M < V.size()) {
				if (V[M - 1] != V[M]) break;
				M++;
			}
			ULL C[51] = {};
			C[0] = 1;
			rep(i, M) {
				C[i + 1] = C[i] * (M - i) / (i + 1);
			}
			ULL ans = 0;
			for (UL i = A; i <= min(M, B); i++) ans += C[i];
			cout << ans << endl;
		}
		else {
			double av = 0.0; rep(i, A) av += V[i];
			cout << (av / A) << endl;
			UL L = A - 1, R = A;
			while (L != 0) { if (V[L - 1] != V[L]) break; L--; }
			while (R < N) { if (V[R - 1] != V[R]) break; R++; }
			ULL C[51] = {};
			C[0] = 1;
			rep(i, R - L) {
				C[i + 1] = C[i] * (R - L - i) / (i + 1);
			}
			cout << C[A - L] << endl;
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
