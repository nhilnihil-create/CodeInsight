#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		string S; cin >> S;
		ULL ans = (S.size() * (S.size() - 1)) / 2;
		UL C[256] = {};
		rep(i, S.size()) {
			ans -= C[S[i]];
			C[S[i]]++;
		}
		cout << (ans + 1) << endl;
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