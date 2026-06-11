#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int N = 100100;
int n, k;
ll a[N];
ll sum[N];
ll pref[N], suf[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	sum[0] = 0;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + a[i];
	pref[0] = 0;
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + max(0LL, a[i]);
	suf[n] = 0;
	for (int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + max(0LL, a[i]);
	ll ans = 0;
	for (int i = 0; i + k <= n; i++)
		ans = max(ans, pref[i] + suf[i + k] + max(0LL, sum[i + k] - sum[i]));
	printf("%lld\n", ans);

	return 0;
}
