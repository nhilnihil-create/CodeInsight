#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
LL h, w, n, ans[10];
LL dx[3] = {-2, -1, 0};
LL dy[3] = {-2, -1, 0};
map <LL, LL> mp;

void add (LL x, LL y)
{
	LL tx, ty;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			tx = x + dx[i];
			ty = y + dy[j];
			if(tx < 1 || ty < 1 || tx > h - 2 || ty > w - 2)
				continue;
			++mp[(tx - 1) * (w - 2)+ty];
		}
}

int main ()
{
	scanf ("%lld%lld%lld", &h, &w, &n);
	for (int i = 1; i <= n; ++i)
	{
		LL x, y;
		scanf ("%lld%lld", &x, &y);
		add (x, y);
	}
	ans[0] = (h - 2) * (w - 2);
	for (map <LL, LL>::iterator it = mp.begin(); it != mp.end(); ++it)
		++ans[it -> second], --ans[0];
	for (int i = 0; i <= 9; ++i)
		printf ("%lld\n", ans[i]);
	return 0;
}