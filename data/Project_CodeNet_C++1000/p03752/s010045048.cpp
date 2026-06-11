#include <bits/stdc++.h>
using namespace std;

#define INF (INT64_MAX/2)

int main()
{
	int N, K;
	cin >> N >> K;
	vector<long long> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	long long ans = INF;
	for( int mask = 0; mask < 1 << N; mask++ ) {
		if( (mask & 1) == 0 ) continue;
		if( __builtin_popcount( mask ) != K ) continue;
		long long cost = 0;
		long long mah = a[0];
		for( int i = 1; i < N; i++ ) {
			long long h = a[i];
			if( mask >> i & 1 ) {
				long long d = 0;
				if( mah >= a[i] ) d = mah - a[i] + 1;
				cost += d;
				h = a[i] + d;
			}
			mah = max( mah, h );
		}
		ans = min( ans, cost );
	}

	cout << ans << endl;
}
