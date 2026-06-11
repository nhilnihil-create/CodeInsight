#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long Q, H, S, D, N;
	cin >> Q >> H >> S >> D >> N;

	H = min( H, 2 * Q );
	S = min( S, 2 * H );
	long long ans = N * S;
	if( D < S * 2 ) ans = N / 2 * D + S * ( N % 2 );

	cout << ans << endl;
}
