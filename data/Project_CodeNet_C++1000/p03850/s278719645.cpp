#include <cstdio>
#include <algorithm>
int N, a[100001], sign[100001], L;
long long f[100001];
int main()
{
	scanf("%d%d", &N, a + 1);
	sign[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		static char in[3];
		scanf("%s", in);
		sign[i] = in[0] == '+' ? 1 : -1;
		scanf("%d", a + i);
		a[i] *= sign[i];
	}
	int L = 0;
	f[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		if (sign[i] == 1)
		{
			for (int j = 0; j <= L; j++)
				f[j] += j & 1 ? -a[i] : a[i];
			for (int j = L - 1; j >= 0; j--)
				f[j] = std::max(f[j], f[j + 1]);
		}
		else
		{
			for (int j = 0; j <= L; j++)
				f[j] += j & 1 ? -a[i] : a[i];
			f[++L] = -1LL << 60;
			for (int j = L; j; j--)
				f[j] = std::max(f[j], f[j - 1]);
			for (int j = L - 1; j >= 0; j--)
				f[j] = std::max(f[j], f[j + 1]);
		}
		while (L > 10)
			L -= 2;
	}
	printf("%lld\n", *std::max_element(f, f + L + 1));
	return 0;
}
