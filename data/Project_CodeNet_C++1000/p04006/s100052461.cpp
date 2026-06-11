#include <bits/stdc++.h>
using namespace std;

#define INF (INT64_MAX/2)

int main()
{
	int N;
	long long x;
	cin >> N >> x;
	vector<int> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	long long ans = INF;
	vector<vector<int>> b( N, vector<int>( N ) );
	for( int k = 0; k < N; k++ ) {
		long long ans1 = 0;
		for( int i = 0; i < N; i++ ) {
			if( k == 0 ) b[k][i] = a[i];
			else {
				int n = i - k;
				if( n < 0 ) n = N - k + i;
				b[k][i] = min( b[k - 1][i], a[n] );
			}
			ans1 += b[k][i];
		}
		ans1 += k * x;
		ans = min( ans, ans1 );
	}

	cout << ans << endl;
}
