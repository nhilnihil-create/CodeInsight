#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> a( N );
	for( int i = 0; i < N; i++ ) {
		cin >> a[i];
	}

	vector<long long> acc( N + 1 );
	vector<long long> accp( N + 1 );
	for( int i = 0; i < N; i++ ) {
		acc[i + 1] = acc[i] + a[i];
		accp[i + 1] = accp[i] + max( a[i], 0 );
	}
	long long ans = 0;
	for( int i = 0; i < N - K + 1; i++ ) {
		long long b = acc[i + K] - acc[i];
		if( i > 0 ) b += accp[i] - accp[0];
		if( i + K < N ) b += accp[N] - accp[i + K];
		long long w = 0;
		if( i > 0 ) w += accp[i] - accp[0];
		if( i + K < N ) w += accp[N] - accp[i + K];
		ans = max( { ans, b, w } );
	}

	cout << ans << endl;
}
