#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		LL N, A, B, C, D; cin >> N >> A >> B >> C >> D;
		N--;
		for (LL i = 0; i <= N; i++) {
			LL l, r;
			l = A + C * i - D * (N - i);
			r = A + D * i - C * (N - i);
			//cout << l << " " << r << endl;
			if (l <= B && B <= r) {
				cout << "YES" << endl;
				return;
			}
		}
		cout << "NO" << endl;
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