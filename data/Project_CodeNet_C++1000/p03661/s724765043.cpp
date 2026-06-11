#include <bits/stdc++.h>

typedef long long LL;

const int MAXN = 2e5 + 5;

int main()
{
	int N; scanf("%d", &N);
	static LL a[MAXN]; LL sum = 0;
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	
	LL pre = a[1], mDif = llabs(sum - 2 * a[1]);
	for (int i = 2; i < N; i++)
	{
		pre += a[i];
		mDif = std::min(mDif, llabs(sum - 2 * pre));
	}
	
	printf("%lld\n", mDif);
}