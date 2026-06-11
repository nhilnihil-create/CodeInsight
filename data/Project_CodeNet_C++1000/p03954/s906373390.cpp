#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	UL N;
	vector<UL> A;

	bool Solve2(UL K) {
		UL l, r; l = r = N - 1;
		while (l != 0) {
			l--; r++;
			if ((A[l] >= K) == (A[l + 1] >= K)) return A[l] >= K;
			if ((A[r] >= K) == (A[r - 1] >= K)) return A[r] >= K;
		}
		return A[0] >= K;
	}

	void Solve() {
		cin >> N;
		A.resize(N * 2 - 1);
		rep(i, N * 2 - 1) cin >> A[i];
		UL l = 0, r = 2 * N + 1;
		while (l + 1 < r) {
			UL m = (l + r) / 2;
			if (Solve2(m)) l = m; else r = m;
		}
		cout << l << endl;
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
