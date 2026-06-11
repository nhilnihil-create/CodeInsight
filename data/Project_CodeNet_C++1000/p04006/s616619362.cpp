#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll x;
ll a[2048];
ll md[2048][2048];
int main()
{
	scanf("%d%lld", &n, &x);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = 0; i < n; i++)
	{
		md[i][i] = a[i];
		for (int j = 1; j < n; j++)
			md[i][(i + j) % n] = min(a[(i + j) % n], md[i][(i + j - 1) % n]);
	}
	ll ans = -1;
	for (int y = 0; y < n; y++)
	{
		ll tot = x * y;
		for (int i = 0; i < n; i++)
		{
			tot += md[i][(i + y) % n];
		}
		if (ans<0 || ans>tot) ans = tot;
	}
	printf("%lld\n", ans);
	return 0;
}
