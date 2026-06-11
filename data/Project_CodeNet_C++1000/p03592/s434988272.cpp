#include "bits/stdc++.h"
using namespace std;
#define long int64_t

int main() {
	ios_base::sync_with_stdio( false );

	int N, M, K;
	cin >> N >> M >> K;

	bool ok = [&]() {
		for( int i = 0; i <= N; ++i ) {
			for( int j = 0; j <= M; ++j ) {
				int x = i * (M - j);
				int y = j * (N - i);
				if( x+y == K ) {
					return true;
				}
			}
		}
		return false;
	}();
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
