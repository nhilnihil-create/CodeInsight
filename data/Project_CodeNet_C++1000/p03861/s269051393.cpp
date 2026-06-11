#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int  main()
{
	ll a, b, x; cin >> a >> b >> x;
	ll ans;
	if (a != 0)
	{
		a--;
		ans = (b/x) - (a / x);
		cout << ans << endl;
	}
	else
	{
		ans = (b/x) - (a / x);
		cout << ans + 1 << endl;
	}
	return 0;
}