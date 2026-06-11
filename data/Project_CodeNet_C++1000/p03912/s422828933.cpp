#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 100010;
int a[maxN];
int b[maxN];
int c[maxN];
ll ans = 0;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		a[tmp]++;
	}
	for (int i = 1; i <= 100000; i++)
	{
		if (a[i] % 2 != 0)
		{
			b[i % m]++;
			a[i]--;
		}
		a[i] /= 2;
		c[i % m] += a[i];
	}
	for (int i = 1; i <= 100000; i++)
		ans += a[i];
	for (int i = 1; i < m; i++)
	{
		if (i + i == m) continue;
		int tmp1 = min(b[i], b[m - i]);
		ans += tmp1;
		b[i] -= tmp1;
		b[m - i] -= tmp1;
		int tmp2 = min(b[i], c[m - i] * 2);
		tmp2 /= 2;
		ans += tmp2;
		b[i] -= 2 * tmp2;
		c[m - i] -= tmp2;
	}
	ans += b[0] / 2;
	if (m % 2 == 0) ans += b[m/2]/2;
	cout << ans << endl;
	return 0;
}