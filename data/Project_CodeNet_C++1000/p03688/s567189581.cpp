#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void No() { cout << "No" << endl; }
	void Yes() { cout << "Yes" << endl; }
	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		sort(A.begin(), A.end());
		UL lower = A[0], higher = A[N - 1];
		if (higher - lower >= 2) { No(); return; }
		if (lower == higher) {
			if(lower > N / 2 && lower != N - 1) { No(); return; }
			else Yes(); return;
		}
		else {
			UL lowerSz = 0;
			rep(i, N) { if (A[i] == lower) lowerSz++; }
			UL higherSz = N - lowerSz;
			if (higherSz == 1) { No(); return; }
			if (lowerSz + 1 > higher) { No(); return; }
			if (higher > lowerSz + higherSz / 2) { No(); return; }
			else Yes(); return;
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