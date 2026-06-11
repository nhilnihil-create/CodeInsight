#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		string A;
		cin >> A;

		long N = A.size();
		long ans = N * (N-1) / 2 + 1;

		vector<int> c( 128 );
		for( int i = 0; i < N; ++i ) {
			c[A[i]] += 1;
		}
		for( int i = 0; i < 128; ++i ) {
			ans -= (long)c[i] * (c[i]-1) / 2;
		}

		cout << ans << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
