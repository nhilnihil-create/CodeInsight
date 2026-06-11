#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 500;
const int MaxM = MaxN * MaxN;

int n;
int pos[MaxN + 1];

int mark[MaxM + 1];
int used[MaxN + 1];

int seq[MaxM + 1];

inline bool construct()
{
	for (int i = 1; i <= n * n; ++i)
	{
		if (mark[i] > 0)
		{
			int k = mark[i];
			if (++used[k] != k)
				return false;
			seq[i] = k;
			continue;
		}

		int cur = 0;
		for (int k = 1; k <= n; ++k)
		{
			if (used[k] >= k - 1 || i > pos[k])
				continue;
			if (cur == 0 || pos[k] < pos[cur])
				cur = k;
		}

		for (int k = 1; !cur && k <= n; ++k)
			if (used[k] < n && i > pos[k])
				cur = k;

		if (!cur)
			return false;

		seq[i] = cur, ++used[cur];
	}

	return true;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> pos[i];
		mark[pos[i]] = i;
	}

	if (!construct())
		puts("No");
	else
	{
		puts("Yes");
		for (int i = 1; i <= n * n; ++i)
			printf("%d ", seq[i]);
	}

	return 0;
}