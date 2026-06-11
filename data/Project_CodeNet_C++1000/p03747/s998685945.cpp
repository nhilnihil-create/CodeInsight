#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, l, t, pos[100007], cnt;
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
signed main()
{
	n = read();
	l = read();
	t = read();
	for (int i = 1; i <= n; i++)
	{
		int a = read(), b = read();
		pos[i] = (a + ((b == 1 ? 1 : -1) * (t % l) + l) % l) % l;
		if (b == 1)cnt += (a + t) / l;
		else cnt -= (t - a + l - 1) / l;
	}
	sort(pos + 1, pos + n + 1);
	cnt = (cnt % n + n) % n;
	for (int i = cnt + 1; i <= n; i++)
		printf("%lld\n", pos[i]);
	for (int i = 1; i <= cnt; i++)
		printf("%lld\n", pos[i]);
	return 0;
}