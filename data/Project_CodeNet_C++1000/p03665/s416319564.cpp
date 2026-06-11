#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, P;
	cin >> N >> P;
	int odd = 0;
	int even = 0;
	for( int i = 0; i < N; i++ ) {
		int A;
		cin >> A;
		if( A % 2 ) odd++;
		else even++;
	}

	long long ans = 0;
	if( odd ) {
		ans = 1;
		for( int i = 0; i < N - 1; i++ ) {
			ans *= 2;
		}
	}
	else if( P % 2 == 0 ) {
		ans = 1;
		for( int i = 0; i < N; i++ ) {
			ans *= 2;
		}
	}

	cout << ans << endl;
}
