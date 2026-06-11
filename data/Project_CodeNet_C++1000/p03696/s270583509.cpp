#include "bits/stdc++.h"
using namespace std;
#define long int64_t

struct Solver {
	Solver() {
		ios::sync_with_stdio( false );
		cout << fixed << setprecision( 10 );
	}

	void solve() {
		int N;
		string S;
		cin >> N >> S;

		string l, r;
		int a = 0;
		int b = 0;
		for( int i = 0; i < N; ++i ) {
			if(      S[i] == '(' ) { a += 1; }
			else if( S[i] == ')' ) { b += 1; }

			if( a < b ) {
				l += '(';
				b -= 1;
			}
		}
		for( int i = 0; i < a-b; ++i ) { r += ')'; }

		cout << l << S << r << endl;
	}
};

int main() {
	Solver().solve();
	return 0;
}
