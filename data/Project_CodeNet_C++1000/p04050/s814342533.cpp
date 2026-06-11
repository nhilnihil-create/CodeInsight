#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
int N, M, A[MAXN];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i ++) scanf("%d", &A[i]);
	int Odd = 0;
	for (int i = 1; i <= M; i ++)
		Odd += A[i] & 1;
	if (Odd >= 3) return puts("Impossible"), 0;
	if (M == 1)
	{
		if (A[1] == 1) return printf("1\n1\n1\n"), 0;
		printf("%d\n", N);
		printf("2\n1 %d\n", N - 1); return 0;
	}
	else if (M == 2)
	{
		if (A[1] == A[2] && A[1] == 1)
		{
			printf("1 1\n 1\n 2");
			return 0;
		}
	}
	Odd = 0;
	for (int i = 1; i <= M; i ++)
	{
		if (A[i] & 1)
		{
			if (!Odd) swap(A[i], A[1]);
			else {swap(A[i], A[M]); break;}
			++ Odd;
		}
	}
	for (int i = 1; i <= M; i ++)
		printf("%d ", A[i]);
	puts("");
	vector<int> ans(0);
	for (int i = 1; i <= M; i ++)
	{
		if (i == 1 && A[i] > 1)
			ans.push_back(A[i] - 1);
		if (i == M) ans.push_back(A[i] + 1);
		else if (i >= 2) ans.push_back(A[i]);
	}
	printf("%d\n", ans.size());
	for (int cur : ans)
		printf("%d ", cur);
	puts("");
	return 0;
}