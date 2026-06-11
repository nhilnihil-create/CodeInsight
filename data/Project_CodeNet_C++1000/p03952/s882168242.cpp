#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, X; cin >> N >> X;
		if (X == 1) { cout << "No" << endl; return; }
		if (X == 2 * N - 1) { cout << "No" << endl; return; }
		cout << "Yes" << endl;
		UL p = 1;
		rep(i, 2 * N - 1) {
			if (i == N - 2) { cout << X + 1 << endl; }
			else if (i == N - 1) { cout << X << endl; }
			else if (i == N) { cout << X - 1 << endl; }
			else {
				if (p == X - 1) p = X + 2;
				cout << p << endl;
				p++;
			}
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
