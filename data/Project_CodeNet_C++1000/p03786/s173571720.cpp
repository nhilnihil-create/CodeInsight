#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A( N );
	for( int i = 0; i < N; i++ )  {
		cin >> A[i];
	}

	sort( A.begin(), A.end() );
	int t = 0;
	long long a = 0;
	for( int i = 0; i < N - 1; i++ )  {
		a += A[i];
		if( a * 2 < A[i + 1] ) t = i + 1;
	}
	int ans = N - t;

	cout << ans << endl;
}
