#include <bits/stdc++.h>
using namespace std;

int dat[100005];
constexpr int MOD = 1000000007;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
	}

	dat[0] = 1;
	for (int i = 1; i < n; i++)
	{
		dat[i] = min(dat[i], dat[i - 1] + 2);
	}

	if (n == 1) printf("1\n");
	else if (n == 2) printf("2\n");
	else
	{
		int ret = 2;
		int cnt = (dat[0] + 1 == dat[1] ? 1 : 0);
		for (int i = 2; i < n; i++)
		{
			ret = ret * 1ll * (i + 1 - (cnt + 1) / 2) % MOD;
			if (dat[i - 1] + 1 == dat[i]) ++cnt;
		}
		printf("%d\n", ret);
	}
}