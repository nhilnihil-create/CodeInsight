#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL A[2000];
	UL m[2000];
	
	void Solve() {
		UL N; cin >> N;
		ULL X; cin >> X;
		rep(i, N) cin >> A[i];
		rep(i, N) m[i] = 1000000001;

		ULL ans = 0;
		rep(i, N) ans += A[i];
		rep(x, N) {
			ULL ansbuf = 0;
			rep(i, N) {
				m[i] = min(m[i], A[(N - x + i) % N]);
				ansbuf += m[i];
			}
			ans = min(ans, ansbuf + X * x);
		}
		cout << ans << endl;
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
