#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long ll;
typedef long double ld;

int  main()
{
	long n, a, b; cin >> n >> a >> b;
	long r = n - 2;

	long ans = 0;
	// if (r <= (b - a + 1))
	ans = (b*r) - (a*r) + 1;
	if (ans > 0)
		cout << ans << endl;
	else
		cout << 0 << endl;
	return 0;
}