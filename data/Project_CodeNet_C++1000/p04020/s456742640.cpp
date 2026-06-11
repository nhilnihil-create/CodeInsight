#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	void solve() {
		int N;
		cin >> N;

		long ans = 0;
		long sum = 0;
		for( int i = 0; i < N; ++i ) {
			int a;
			cin >> a;
			if( a == 0 ) {
				ans += sum / 2;
				sum = 0;
			}
			else {
				sum += a;
			}
		}
		ans += sum / 2;
		cout << ans << endl;
	}
};

int main() {
	ios::sync_with_stdio( false );
	cout << fixed << setprecision( 10 );
	Solver().solve();

	return 0;
}
