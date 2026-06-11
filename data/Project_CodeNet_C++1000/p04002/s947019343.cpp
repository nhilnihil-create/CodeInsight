#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

const int N(1e5 + 10);
std::set<std::pair<int, int> > P[10];
std::set<std::pair<int, int> > B;
int n, H, W, a[N], b[N];
long long ans[10];

int main()
{
	scanf("%d%d%d", &H, &W, &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);
	for (int i = 1; i <= n; i++) B.insert(std::make_pair(a[i], b[i]));
	for (int t = 1; t <= n; t++)
	{
		int dx = std::max(a[t] - 2, 1), dy = std::max(b[t] - 2, 1);
		for (int x = dx; x <= a[t] && x + 2 <= H; x++)
			for (int y = dy; y <= b[t] && y + 2 <= W; y++)
			{
				int cnt = 0;
				for (int i = x; i < x + 3; i++)
					for (int j = y; j < y + 3; j++)
						cnt += (B.find(std::make_pair(i, j)) != B.end());
				P[cnt].insert(std::make_pair(x, y));
			}
	}
	ans[0] = 1ll * (H - 2) * (W - 2);
	for (int i = 1; i <= 9; i++) ans[i] = P[i].size(), ans[0] -= ans[i];
	for (int i = 0; i <= 9; i++) printf("%lld\n", ans[i]);
	return 0;
}
