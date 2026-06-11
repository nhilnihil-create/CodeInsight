#include <cstdio>
const int MOD = 1000000007;
int N, f[1000001], s[1000001];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
			f[i] = N;
		else if (i == 2)
			f[i] = (long long)N * N % MOD;
		else
			f[i] = (f[i - 1] + s[i - 3] + (long long)N * (N - 1) - i + 3) % MOD;
		s[i] = (s[i - 1] + f[i]) %MOD;
	}
	printf("%d\n", f[N]);
	return 0;
}
