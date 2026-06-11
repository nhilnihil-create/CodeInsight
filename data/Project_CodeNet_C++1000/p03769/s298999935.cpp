#include <bits/stdc++.h>
using namespace std;

deque <int> De;
int cnt, cnt1, cnt2, front[105], back[105];
long long n;
void work(long long x)
{
	if (!x) return ;
	if (!(x & 1)) ++cnt, front[++cnt1] = cnt, work(x - 1);
	else ++cnt, back[++cnt2] = cnt, work(x >> 1);
}
int main()
{
	scanf("%lld", &n);
	work(n);
	printf("%d\n", cnt + 100);
	for (int i = 1; i <= cnt1; i++)
		printf("%d ", cnt - front[i] + 1);
	for (int i = cnt2; i >= 1; i--)
		printf("%d ", cnt - back[i] + 1);
	for (int i = 1; i <= 100; i++)
		printf("%d ", i);
	return 0;
}