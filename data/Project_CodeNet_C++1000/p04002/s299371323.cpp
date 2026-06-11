#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
ll inf = (ll)1e9 + 7;
ll a[900009];
ll sum[20];
int dx[] = { 0,-1,-2,0,-1,-2,0,-1,-2 };
int dy[] = { 0,0,0,-1,-1,-1,-2,-2,-2 };
int main()
{
	ll h, m, n;
	scanf("%lld%lld%lld", &h, &m, &n);
	ll x, y;
	int k = 0;
	ll zo = (h - 2) * (m - 2);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld%lld", &x, &y);
		for (ll j = 0; j < 9; j++) {
			ll xn = x + dx[j], yn = y + dy[j];
			if (xn<1 || xn>h - 2 || yn < 1 || yn>m - 2)continue;
			a[k++] = inf * xn + yn;
		}
	}
	sort(a, a + k);
	ll t = 1;
	for (int i = 0; i < k; i++) {
		if (a[i] == a[i + 1])t++;
		else {
			sum[t]++; t = 1;
			zo--;
		}
	}
	printf("%lld\n", zo);
	for (int i = 1; i <= 9; i++)
		printf("%lld\n", sum[i]);
	return 0;
}