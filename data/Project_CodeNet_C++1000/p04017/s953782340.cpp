#include <bits/stdc++.h>

int main()
{
	int N;
	scanf("%d", &N);
	std::vector<int64_t> x(N + 1);
	for (int i{}; i < N; i++) scanf("%lld", &x[i]);
	x[N] = x[N - 1] + 1;
	int64_t L;
	scanf("%lld", &L);

	using vi = std::vector<int>;
	int size{1};
	while ((1 << (size - 1)) < N) size++;
	std::vector<vi> table(N + 1, vi(size));
	table.back()[0] = N;
	for (int i{N - 1}, prev{N}; i >= 0; i--)
	{
		while (x[prev] > x[i] + L)
			prev--;
		table[i][0] = prev;
	}
	for (int i{}; i + 1 < size; i++)
		for (int j{}; j <= N; j++)
			table[j][i + 1] = table[table[j][i]][i];
	

	// for (int i{}; i < N; i++)
	// {
	// 	printf("%lld: ", x[i]);
	// 	for (auto& f: table[i]) printf("%d ", f);
	// 	putchar('\n');
	// }
	int Q;
	scanf("%d", &Q);
	for (int i{}; i < Q; i++)
	{
		int from, to;
		scanf("%d%d", &from, &to);
		from--;
		to--;
		if (from > to) std::swap(from, to);
		int ans{}, now{from};
		for (int i{size - 1}; i >= 0; i--)
		{
			if (table[now][i] > to) continue;
			ans += 1 << i;
			now = table[now][i];
		}
		if (now < to) ans++;
		printf("%d\n", ans);
	}

	return 0;
}