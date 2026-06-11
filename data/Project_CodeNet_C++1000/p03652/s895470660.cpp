#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL A[300][300];
	UL P[300];
	bool F[300];

	void Solve() {
		UL N, M; cin >> N >> M;
		rep(i, N) rep(j, M) { cin >> A[i][j]; A[i][j]--; }
		rep(i, N) P[i] = 0;
		rep(i, M) F[i] = false;

		UL ans = 10000;
		rep(i, M) {
			UL p[300] = {};
			rep(j, N) p[A[j][P[j]]]++;
			UL ansbuf = 0;
			UL maxp = 0;
			rep(j, M) {
				if (ansbuf < p[j]) { maxp = j; ansbuf = p[j]; }
			}
			ans = min(ans, ansbuf);
			F[maxp] = true;
			//rep(j, N) cout << A[j][P[j]] << " "; cout << endl;
			if (i != M - 1) {
				rep(j, N) while (F[A[j][P[j]]]) P[j]++;
			}
		}
		cout << ans << endl;
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