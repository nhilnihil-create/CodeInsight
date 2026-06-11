#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve(){
		UL N, M; cin >> N >> M;
		vector<pair<UL, UL>> Q(M); rep(i, M) cin >> Q[i].first >> Q[i].second;
		vector<UL> C(N);
		rep(i, M) { C[Q[i].first - 1]++; C[Q[i].second - 1]++; }
		bool ok = true;
		rep(i, N) { if (C[i] & 1) ok = false; }
		cout << (ok ? "YES" : "NO") << endl;
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