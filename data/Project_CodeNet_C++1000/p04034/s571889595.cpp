#include <bits/stdc++.h>
#define LL long long
#define F(i, a, b) for(int i = a; i <= b; ++i)

using namespace std;

const int maxn = 1e5 + 5;
int n, m, cnt[maxn];
bool able[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	able[1] = true;
	F(i, 1, n) cnt[i] = 1;
	F(i, 1, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		able[y] |= able[x];
		--cnt[x], ++cnt[y];
		if(cnt[x] == 0) able[x] = false;
	}
	int ans = 0;
	F(i, 1, n) if(able[i]) ++ans;
	printf("%d", ans);
	return 0;
}