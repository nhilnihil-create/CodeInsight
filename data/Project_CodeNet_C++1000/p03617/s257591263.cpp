#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<long long> cost( 4 );
	for( int i = 0; i < 4; i++ ) {
		cin >> cost[i];
	}
	long long N;
	cin >> N;

	double l[4] = { 0.25, 0.5, 1, 2 };
	long long ans = INT64_MAX / 2;
	for( int mask = 0; mask < 1 << 4; mask++ ) {
		long long s = 0;
		long long n = N;
		int bit = 0;
		for( int i = 3; i >= 0; i-- ) {
			if( mask >> i & 1 ) {
				long long d = floor( n / l[i] );
				if( bit + 1 == __builtin_popcount( mask ) ) d = ceil( n / l[i] );
				s += d * cost[i];
				n -= d * l[i];
				bit++;
			}
		}
		if( s == 0 || n != 0 ) continue;
		ans = min( ans, s );
	}

	cout << ans << endl;
}
