#include <cstdio>
#include <algorithm>
int N, M, a[100], b[100];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", a + i);
	if (M == 1)
	{
		if (N == 1)
			puts("1\n1\n1");
		else
			printf("%d\n2\n1 %d\n", N, N - 1);
		return 0;
	}
	int Odd = std::count_if(a, a + M, [] (int x) { return x & 1; });
	if (Odd > 2)
	{
		puts("Impossible");
		return 0;
	}
	if (Odd == 2)
	{
		int C = 1;
		for (int i = 0; i < M; i++)
			if (!(a[i] & 1))
				b[C++] = a[i];
			else
				(b[0] ? b[M - 1] : b[0]) = a[i];
		for (int i = 0; i < M; i++)
			printf("%d%c", b[i], " \n"[i == M - 1]);
		b[0]++;
		b[M - 1]--;
		if (!b[M - 1])
			M--;
		printf("%d\n", M);
		for (int i = 0; i < M; i++)
			printf("%d%c", b[i], " \n"[i == M - 1]);
		return 0;
	}
	if (Odd == 1)
	{
		int C = 1;
		for (int i = 0; i < M; i++)
			if (!(a[i] & 1))
				b[C++] = a[i];
			else
				b[0] = a[i];
		for (int i = 0; i < M; i++)
			printf("%d%c", b[i], " \n"[i == M - 1]);
		b[0]++;
		b[M - 1]--;
		printf("%d\n", M);
		for (int i = 0; i < M; i++)
			printf("%d%c", b[i], " \n"[i == M - 1]);
		return 0;
	}
	for (int i = 0; i < M; i++)
		printf("%d%c", a[i], " \n"[i == M - 1]);
	a[0]++;
	a[M - 1]--;
	printf("%d\n", M);
	for (int i = 0; i < M; i++)
		printf("%d%c", a[i], " \n"[i == M - 1]);
	return 0;
}
