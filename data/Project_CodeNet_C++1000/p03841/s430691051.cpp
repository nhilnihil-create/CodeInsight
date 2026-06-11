#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 505
int n, cnt[N], X[N];
int ans[N * N];
struct Node
{
	int x, id;
}A[N];
bool cmp(Node a, Node b){return a.x < b.x;}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &X[i]);
		A[i].x = X[i];
		A[i].id = i;
	}
	sort(A + 1, A + n + 1, cmp);
	int p = 1;
	for (int i = 1; i <= n * n; i++)
	{
		if (i == A[p].x)
		{
			if (cnt[A[p].id] == A[p].id - 1)
			{
				ans[i] = A[p].id;
				cnt[A[p].id]++;
			}
			else
			{
				puts("No");
				return 0;
			}
			p++;
		}
		else
		{
			int m = n + 1;
			for (int j = 1; j <= n; j++)
				if (cnt[j] < j - 1)
					if (m == n + 1 || X[j] < X[m])
						m = j;
			if (m == n + 1)
			{
				for (int j = 1; j <= n; j++)
					if (cnt[j] >= j && cnt[j] < n)
						m = j;
				if (m == n + 1)
				{
					puts("No");
					return 0;
				}
			}
			ans[i] = m;
			cnt[m]++;
		}
	}
	puts("Yes");
	for (int i = 1; i <= n * n; i++)
		printf("%d%c", ans[i], i == n * n ? 10 : 32);
}
