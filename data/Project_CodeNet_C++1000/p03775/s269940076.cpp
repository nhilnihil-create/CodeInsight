#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N;
	cin >> N;

	auto f = []( long long n ) -> int
	{
		int d = 0;
		while( n > 0 ) {
			d++;
			n /= 10;
		}
		return d;
	};
	int ans = f( N );
	for( long long i = 2; i * i <= N; i++ ) {
		if( N % i ) continue;
		long long A = i;
		long long B = N / A;
		ans = min( ans, max( f( A ), f( B ) ) );
	}

	cout << ans << endl;
}
