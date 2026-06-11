#include<bits/stdc++.h>
using namespace std;
const int N = 109;
int n, m, q, cnt, A[N], B[N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &A[i]), cnt += (A[i] & 1);
	if (cnt > 2)
		return !printf("Impossible\n");
	if (n == 1)
		return !printf("%d\n1\n1\n", A[1]);
	if (m == 1)
		return !printf("%d\n2\n%d %d\n", A[1], A[1] - 1, 1);
	for (int i = 1; i <= m; i++)
		if (A[i] & 1)
			swap(A[i], A[1]);
	for (int i = 2; i <= m; i++)
		if (A[i] & 1)
			swap(A[i], A[m]);
	for (int i = 1; i <= m; i++)
		printf("%d ", A[i]);
	printf("\n");
	if (A[1] > 1)
		B[++ q] = A[1] - 1;
	for (int i = 2; i < m; i++)
		B[++ q] = A[i];
	B[++ q] = A[m] + 1;
	printf("%d\n", q);
	for (int i = 1; i <= q; i++)
		printf("%d ", B[i]);
	printf("\n");
	return 0;
}