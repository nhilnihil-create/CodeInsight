#include <deque>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

deque<int> a, b;

int Solve(LL n)
{
	if (n == 1)
	{
		a.push_front(1);
		b.push_front(1);
		return 1;
	}
	if (n & 1)
	{
		int p = Solve(n >> 1) + 1;
		a.push_back(p);
		b.push_back(p);
		return p;
	}
	else
	{
		int p = Solve(n - 1) + 1;
		a.push_front(p);
		b.push_back(p);
		return p;
	}
}

int main()
{
	LL n;
	scanf("%lld", &n);
	Solve(n);
	printf("%d\n", a.size() + b.size());
	for (; !a.empty(); a.pop_front()) printf("%d ", a.front());
	for (; !b.empty(); b.pop_front()) printf("%d ", b.front());
	return 0;
}
