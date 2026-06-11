#include<bits/stdc++.h>
using namespace std;

map< pair<int, int>, int> H;
int h, w, n;
long long ans[10];

int main()
{
	scanf("%d %d %d", &h, &w, &n);
	ans[0] = (long long)(h - 2) * (w - 2);
	for(int i = 1; i <= n; ++i)
	{
		int x, y; scanf("%d %d", &x, &y);
		for(int dx = x; dx <= x + 2; ++dx)
			for(int dy = y; dy <= y + 2; ++dy)
				if(dx >= 3 && dx <= h && dy >= 3 && dy <= w)
				{
					ans[H[make_pair(dx, dy)]]--;
					ans[++H[make_pair(dx, dy)]]++;
				}
	}
	for(int i = 0; i <= 9; ++i) printf("%lld\n", ans[i]);
	return 0;
}