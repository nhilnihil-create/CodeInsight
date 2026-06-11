#include <cstdio>
#include <algorithm>
int N, a[501], O[250001], L[501], R[501], C[501], A[501];
std::pair < int, int > p[501];
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", a + i);
		O[a[i]] = i;
		L[i] = i - 1;
		R[i] = N - i;
		p[i] = { a[i], i };
	}
	std::sort(p + 1, p + N + 1);
	for (int i = 1, c = 1; i <= N * N; i++)
		if (!O[i])
		{
			while (c <= N && !L[p[c].second])
				c++;
			if (c > N)
				break;
			O[i] = p[c].second;
			L[p[c].second]--;
		}
	for (int i = N * N, c = N; i; i--)
		if (!O[i])
		{
			while (c && !R[p[c].second])
				c--;
			if (!c)
				break;
			O[i] = p[c].second;
			R[p[c].second]--;
		}
	for (int i = 1; i <= N * N; i++)
		if (++C[O[i]] == O[i])
			A[O[i]] = i;
	for (int i = 1; i <= N; i++)
		if (A[i] != a[i] || C[i] != N)
		{
			puts("No");
			return 0;
		}
	puts("Yes");
	for (int i = 1; i <= N * N; i++)
		printf("%d%c", O[i], " \n"[i == N * N]);
	return 0;
}
