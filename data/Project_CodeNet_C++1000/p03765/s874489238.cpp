#include <bits/stdc++.h>

int main()
{
	std::string S, T;
	std::cin >> S >> T;
	std::vector<int> sSum(S.size() + 1), tSum(T.size() + 1);
	for (int i{}; i < (int)S.size(); i++)
	{
		sSum[i + 1] = sSum[i];
		if (S[i] == 'A') sSum[i + 1] += 2;
		else sSum[i + 1] += 1;
	}
	for (int i{}; i < (int)T.size(); i++)
	{
		tSum[i + 1] = tSum[i];
		if (T[i] == 'A') tSum[i + 1] += 2;
		else tSum[i + 1] += 1;
	}

	int q;
	scanf("%d", &q);
	for (int i{}; i < q; i++)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a--; c--;
		if ((sSum[b] - sSum[a]) % 3 == (tSum[d] - tSum[c]) % 3)
			puts("YES");
		else
			puts("NO");
	}

	return 0;
}