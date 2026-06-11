#include <cstdio>
#include <vector>
#include <algorithm>
long long N;
int num[60], L = -1, d = 1, u;
int main()
{
	scanf("%lld", &N);
	N++;
	while (N)
	{
		num[++L] = N & 1;
		N >>= 1;
	}
	std::vector < int > O;
	for (int i = L - 1; ~i; i--)
	{
		O.push_back(++u);
		if (num[i])
			O.push_back(--d);
	}
	printf("%d\n", int(O.size()) << 1);
	for (int i = 1; i <= int(O.size()); i++)
		printf("%d ", i);
	for (int i : O)
		printf("%d ", i + 1 - d);
	putchar(10);
	return 0;
}
