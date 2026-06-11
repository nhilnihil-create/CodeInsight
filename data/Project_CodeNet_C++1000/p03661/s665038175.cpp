#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;

ll gcd(ll aaa,ll bbb) {
    if(bbb==0) {
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}

ll lcm(ll m,ll n)
{
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m / gcd(m, n)) * n);
}

int main() {

	long N;
	cin >> N;
	long a[N],s[N+1];
	s[0] = 0;
	for(long i = 0; i < N; i++) {
		cin >> a[i];
		s[i+1] = a[i] + s[i];
	}

	long M = 1e20;
	for(long i = 1; i < N; i++) {
		M = min(M,abs(s[i] - (s[N] - s[i])));
	}
	cout << M << endl;

	return 0;
}
