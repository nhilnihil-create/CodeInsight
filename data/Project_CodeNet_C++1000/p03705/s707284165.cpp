#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long N, A, B;
	cin >> N >> A >> B;

	long long ma = (N - 1) * B + A;
	long long mi = (N - 1) * A + B;
	long long ans = max( 0LL, ma - mi + 1 );

	cout << ans << endl;
}
