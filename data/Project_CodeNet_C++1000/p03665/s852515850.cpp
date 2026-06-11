#include <bits/stdc++.h>
using namespace std;

long long combi(long long n, long long r)
{
    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (combi(n - 1, r - 1) + combi(n - 1, r));
}

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
	if( P % 2 ) {
		for( int i = 1; i <= odd; i += 2 ) {
			ans += combi(odd, i);
		}
		long long p = 1;
		for( int i = 0; i < even; i++ ) {
			p *= 2;
		}
		ans *= p;
	}
	else {
		for( int i = 0; i <= odd; i += 2 ) {
			ans += combi(odd, i);
		}
		if( ans == 0 ) ans = 1;
		long long p = 1;
		for( int i = 0; i < even; i++ ) {
			p *= 2;
		}
		ans *= p;
	}

	cout << ans << endl;
}
