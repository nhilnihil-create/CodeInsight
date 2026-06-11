#include <bits/stdc++.h>
using namespace std;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

long long ans;

void solve(long long a, long long b)
{
	if (a % b == 0) return ans += (a << 1) - b, void();
	ans += a / b * b * 2;
	solve(b, a % b);
}

int main()
{
	long long n, x;
	scanf("%lld%lld", &n, &x);
	ans = n;
	if (x < n - x) x = n - x;
	solve(x, n - x);
	printf("%lld\n", ans);
	
	return 0;
}

