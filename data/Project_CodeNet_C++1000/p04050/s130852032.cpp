/*
首先特判掉M = 1的情况 
对于一个区间[l, r]是回文串的性质，可以写出floor((r - l + 1) / 2)个限制：S[a] = S[b](a != b)，对于这样的限制连一条无向边(a, b)
设A数组中有s1个奇数，那么连了(N - s1) / 2条边；B数组有s2个奇数，那么连了(N - s2) / 2条边。那么一共连了N - (s1 + s2) / 2条边
要求所有字符必须相同，那么需要满足整个图是联通的，故N - (s1 + s2) / 2 >= N - 1   =>   s1 + s2 <= 2。当s1 > 2时一定无解 
当s1 <= 2时，存在这么一种构造方法。把A的奇数放在两端，令B[1] = A[1] - 1   B[M] = A[M] + 1   B[2 <= i <= M - 1] = A[i]即可
这样可以让整张图至少包含一条连接所有点的链，也就完成了构造 
*/

#include <cstdio>
#include <algorithm>

using namespace std;
const int Max_M(105);

int N, M, A[Max_M], B[Max_M];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1;i <= M;++i)
		scanf("%d", A + i), A[0] += (A[i] & 1);
	if (M == 1)
	{
		if (A[1] == 1)
			printf("%d\n%d\n%d", 1, 1, 1);
		else
			printf("%d\n%d\n%d %d", A[1], 2, A[1] - 1, 1);
		return 0;
	}
	if (A[0] > 2)
	{
		puts("Impossible");
		return 0;
	}
	for (int i = 1;i <= M;++i)
		if (A[i] & 1)
		{
			swap(A[1], A[i]);
			break;
		}
	for (int i = M;i >= 1;--i)
		if (A[i] & 1)
		{
			swap(A[M], A[i]);
			break;
		}
	if (A[1] - 1)
		B[++B[0]] = A[1] - 1;
	for (int i = 2;i <= M - 1;++i)
		B[++B[0]] = A[i];
	B[++B[0]] = A[M] + 1;
	for (int i = 1;i <= M;++i)
		printf("%d ", A[i]);
	printf("\n");
	printf("%d\n", B[0]);
	for (int i = 1;i <= B[0];++i)
		printf("%d ", B[i]);
	return 0;
}