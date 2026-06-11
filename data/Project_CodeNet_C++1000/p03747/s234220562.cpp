#include <cstdio>
#include <algorithm>

const int N(1e5 + 10);
int n, L, T, x[N], sum;

int main()
{
	scanf("%d%d%d", &n, &L, &T);
	for (int i = 1, w; i <= n; i++)
	{
		scanf("%d%d", x + i, &w);
		if (w == 1 && T - L + x[i] >= 0) sum += (T - L + x[i]) / L + 1;
		else if (w == 2 && T - x[i] > 0) sum -= (T - x[i] - 1) / L + 1;
		if (w == 1) x[i] = (x[i] + T) % L;
		else x[i] = (x[i] - T % L + L) % L;
	}
	std::sort(x + 1, x + n + 1), sum = (sum % n + n) % n;
	for (int i = sum + 1; i <= n; i++) printf("%d\n", x[i]);
	for (int i = 1; i <= sum; i++) printf("%d\n", x[i]);
	return 0;
}
