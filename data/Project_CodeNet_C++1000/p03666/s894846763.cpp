#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;

	string ans = "NO";
	long long diff = B - A;
	for( int n = 0; n < N; n++ ) {
		if( (N - 1 - n) * C - n * D <= diff && diff <= (N - 1 - n) * D - n * C ) {
			ans = "YES";
		}
	}

	cout << ans << endl;
}
