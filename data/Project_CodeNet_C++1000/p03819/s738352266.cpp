#include <cstdio>
#include <algorithm>
#include <vector>
int N, M, root[100001], T[9000001], ls[9000001], rs[9000001], n;
std::vector < int > ins[100001];
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1, l, r; i <= N; i++)
	{
		scanf("%d%d", &l, &r);
		ins[l].push_back(r);
	}
	for (int i = 1; i <= M; i++)
	{
		root[i] = root[i - 1];
		for (int x : ins[i])
		{
			int p = root[i], nrt = ++n, l = 1, r = M;
			T[n] = T[p] + 1;
			while (l < r)
			{
				int m = l + r >> 1;
				if (x <= m)
					ls[n] = n + 1, rs[n] = rs[p], p = ls[p], r = m;
				else
					rs[n] = n + 1, ls[n] = ls[p], p = rs[p], l = m + 1;
				T[++n] = T[p] + 1;
			}
			root[i] = nrt;
		}
	}
	for (int i = 1; i <= M; i++)
	{
		int S = 0;
		for (int j = i; j <= M; j += i)
		{
			int pl = root[j - i], pr = root[j], l = 1, r = M;
			while (l < r)
			{
				int m = l + r >> 1;
				if (j <= m)
					S += T[rs[pr]] - T[rs[pl]], pl = ls[pl], pr = ls[pr], r = m;
				else
					pl = rs[pl], pr = rs[pr], l = m + 1;
			}
			S += T[pr] - T[pl];
		}
		printf("%d\n", S);
	}
	return 0;
}
