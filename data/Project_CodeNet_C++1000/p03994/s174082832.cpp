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
		UL N; N = S.size();
		vector<UL> A(N);
		rep(i, N) A[i] = S[i] - 'a';
		UL K; cin >> K;
		rep(i, N) {
			if (A[i] == 0) continue;
			if (26 - A[i] <= K) {
				K -= 26 - A[i];
				A[i] = 0;
			}
		}
		A.back() = (A.back() + K) % 26;
		rep(i, N) cout << (char)(A[i] + 'a');
		cout << endl;
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
