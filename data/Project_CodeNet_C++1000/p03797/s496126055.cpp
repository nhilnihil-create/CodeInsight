#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
	ll s, c;
	cin >> s >> c;
	
	ll ans = 0;
	ll t = c / 2;
	
	if (s > t) {
		cout << t;
		return 0;
	}
	else {
		ans += s;
		c -= (s * 2);
		ans += (c / 4);
	}
	
	
	cout << ans;
	return 0;
}
