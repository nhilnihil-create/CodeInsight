#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

bool f(const pair<UL, UL> &l, const pair<UL, UL> &r) {
	return make_pair(~l.first, l.second) < make_pair(~r.first, r.second);
}

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<pair<UL, UL>> A(N); rep(i, N) { cin >> A[i].first; A[i].second = i; }
		UL p = 0; rep(i, N) p = max(p, A[i].first);
		sort(A.begin(), A.end(), f);
		UL n = 0;
		UL m = N - 1;
		vector<ULL> ans(N);
		rep(i, N) {
			ans[m] += ULL(n) * (p - A[i].first);
			p = A[i].first;
			n++;
			m = min(m, A[i].second);
		}
		ans[0] += ULL(n) * p;
		rep(i, N) cout << ans[i] << endl;
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
