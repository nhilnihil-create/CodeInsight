#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

signed main(void)
{
	int n;
	cin >> n;
	ll t[n], a[n];
	ll taka, aoki;
	rep(i,  n) cin >> t[i] >> a[i];
	taka = 1;
	aoki = 1;
	rep(i, n)
	{
		ll tmp_a, tmp_t;
		tmp_a = aoki / a[i];
		if (aoki % a[i] != 0) tmp_a++;	
		tmp_t = taka / t[i];
		if (taka % t[i] != 0) tmp_t++;	
		ll p = max(tmp_a, tmp_t);
		aoki = p * a[i];
		taka = p * t[i];
	}
	cout << taka + aoki << endl;
	return 0;
}
