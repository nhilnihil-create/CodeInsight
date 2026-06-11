#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ll a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	// どこかの面が偶数のときは、そこで面を切れば差が0になる
	if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
		printf("0\n");
	}
	// 偶数がないときはなるべく差が少ない面で切る
	else {
		ll ans = 0;
		// 体積の差は1直方体分
		ans =  min({a * b, a * c, b * c});
		printf("%lld\n", ans);
	}
	return 0;
}