#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 5;

inline int gi()
{
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	int sum = 0;
	while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
	return sum;
}

ll n;
int tot;
vector<int> p, q;

void solve(ll n)
{
	if (!n) return ;
	if (~n & 1) p.push_back(tot++), solve(n - 1);
	else q.push_back(tot++), solve(n >> 1);
}

int main()
{
	scanf("%lld", &n);
	solve(n);
	printf("%d\n", tot + 100);
	for (int x : p) printf("%d ", tot - x);
	reverse(q.begin(), q.end());
	for (int x : q) printf("%d ", tot - x);
	for (int i = 1; i <= 100; ++i) printf("%d ", i);
	
	return 0;
}
