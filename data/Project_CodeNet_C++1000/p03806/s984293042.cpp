#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL dp[401][401][11];

	void Solve() {
		UL N; cin >> N;
		pair<UL, UL> M; cin >> M.first >> M.second;
		vector<pair<UL, UL>> A(N);
		vector<UL> C(N);
		rep(i, N) cin >> A[i].first >> A[i].second >> C[i];

		for (UL x = 0; x <= N * 10; x++) {
			for (UL y = 0; y <= N * 10; y++) {
				dp[x][y][0] = 1000000000;
			}
		}
		dp[0][0][0] = 0;

		rep(i, N) {
			for (UL x = 0; x <= N * 10; x++) {
				for (UL y = 0; y <= N * 10; y++) {
					UL p = dp[x][y][i];
					if (x >= A[i].first && y >= A[i].second) {
						p = min(p, dp[x - A[i].first][y - A[i].second][i] + C[i]);
					}
					dp[x][y][i + 1] = p;
				}
			}
		}
		UL ans = 1000000000;
		for (UL i = 1;; i++) {
			if (M.first * i > N * 10) break;
			if (M.second * i > N * 10) break;
			ans = min(ans, dp[M.first * i][M.second * i][N]);
		}
		if (ans == 1000000000) { cout << -1 << endl; return; }
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
