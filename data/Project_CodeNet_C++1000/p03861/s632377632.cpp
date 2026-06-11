#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long a, b, x;
	cin >> a >> b >> x;

	long long ans = b / x + 1;
	if( a == 0 ) ;
	else ans -= (a - 1) / x + 1;

	cout << ans << endl;
}
