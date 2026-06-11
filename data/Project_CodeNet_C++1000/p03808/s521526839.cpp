#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		LL N; cin >> N;
		vector<LL> A(N); rep(i, N) cin >> A[i];
		ULL S = 0; rep(i, N) S += A[i];
		if (S % (N * (N + 1) / 2) != 0) { cout << "NO" << endl; return; }
		vector<LL> dA(N); rep(i, N - 1) dA[i] = A[i + 1] - A[i]; dA[N - 1] = A[0] - A[N - 1];
		LL moves = S / (N * (N + 1) / 2);
		rep(i, N) dA[i] -= moves;
		//rep(i, N) cout << dA[i] << " "; cout << endl;
		rep(i, N) {
			if (dA[i] > 0) { cout << "NO" << endl; return; }
			if (-dA[i] % N) { cout << "NO" << endl; return; }
			dA[i] = (-dA[i]) / N;
		}
		cout << "YES" << endl;
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