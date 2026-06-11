#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL W, H; cin >> W >> H;
		vector<pair<ULL, int>> P(W + H);
		rep(i, W) { cin >> P[i].first; P[i].second = i + 1; }
		rep(i, H) { cin >> P[i + W].first; P[i + W].second = -((int)i + 1); }
		sort(P.begin(), P.end());
		ULL ans = 0;
		ULL w = W + 1, h = H + 1;
		rep(i, W + H) {
			ULL p = P[i].first;
			if (P[i].second > 0) {
				ans += h * p; w--;
			}
			else {
				ans += w * p; h--;
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
