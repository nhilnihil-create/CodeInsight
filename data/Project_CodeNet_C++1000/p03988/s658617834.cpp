#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N); rep(i, N) cin >> A[i];
		sort(A.begin(), A.end());
		vector<UL> DA(N); rep(i, N) DA[A[i]]++;
		UL m = A[0], M = A[N - 1];
		if (DA[m] == 1) {
			if (m * 2 != M) { cout << "Impossible" << endl; return; }
			for (UL p = m + 1; p <= M; p++) {
				if (DA[p] < 2) { cout << "Impossible" << endl; return; }
			}
			cout << "Possible" << endl;
			return;
		}
		else if (DA[m] == 2) {
			if (m * 2 - 1 != M) { cout << "Impossible" << endl; return; }
			for (UL p = m + 1; p <= M; p++) {
				if (DA[p] < 2) { cout << "Impossible" << endl; return; }
			}
			cout << "Possible" << endl;
			return;
		}
		cout << "Impossible" << endl;
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
