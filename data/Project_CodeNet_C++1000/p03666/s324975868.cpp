#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a, b, c, d;
bool check(ll l, ll r)
{
	bool flag = 0;
	for(int k = -(n - 2); k <= n - 2; k += 2)
	{
		ll nl = l - c * k, nr = r - c * k;
		if(d - c == 0) flag |= (nl <= 0 && 0 <= nr);
		else
		{
			nr = nr >= 0 ? nr / (d - c) : (nr - (d - c - 1)) / (d - c);
			nl = nl >= 0 ? (nl + d - c - 1) / (d - c) : nl / (d - c);
			if(nl > nr) continue;
			flag |= (abs(nl) + abs(k - nl) <= n - 2);
			flag |= (abs(nr) + abs(k - nr) <= n - 2);
			flag |= (nl <= 0 && 0 <= nr);
			flag |= (nl <= k && k <= nr);
			//if(flag) { cout << l << ' ' << r << ' ' << nl << ' ' << nr << ' ' << k << ' ' << n << endl; system("pause");}
		}
	}
	return flag;
}
int main()
{
	cin >> n >> a >> b >> c >> d;
	b -= a;
	if(check(b - d, b - c) || check(b + c, b + d)) puts("YES");
	else puts("NO");
	return 0;
}