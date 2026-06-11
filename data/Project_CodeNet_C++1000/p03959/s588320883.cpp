#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
	int N;
	cin >> N;
	vector<int> T( N );
	for( int i = 0; i < N; i++ ) {
		cin >> T[i];
	}
	vector<int> A( N );
	for( int i = 0; i < N; i++ ) {
		cin >> A[i];
	}

	if( T[N - 1] != A[0] ) {
		cout << 0 << endl;
		return 0;
	}
	vector<int> t( N );
	for( int i = 0; i < N; i++ ) {
		if( i == 0 ) t[i] = 1;
		else if( T[i] > T[i - 1] ) t[i] = 1;
		if( t[i] && A[i] < T[i] ) {
			cout << 0 << endl;
			return 0;
		}
	}
	vector<int> a( N );
	for( int i = N - 1; i >= 0; i-- ) {
		if( i == N - 1 ) a[i] = 1;
		else if( A[i] > A[i + 1] ) a[i] = 1;
		if( a[i] && A[i] > T[i] ) {
			cout << 0 << endl;
			return 0;
		}
	}
	long long ans = 1;
	for( int i = 0; i < N; i++ ) {
		if( t[i] || a[i] ) {
			continue;
		}
		ans *= min( T[i], A[i] );
		ans %= MOD;
	}

	cout << ans << endl;
}
