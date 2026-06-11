#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int a[maxn], b[maxn];
bool check(int mid)
{
	for(int i = 1; i <= 2 * n - 1; ++i) b[i] = (a[i] > mid);
	for(int j = 1; j <= n - 1; ++j)
	{
		if(b[n - j] == b[n - j + 1]) return b[n - j];
		if(b[n + j] == b[n + j - 1]) return b[n + j];
	}
	if(n & 1) return b[n];
	else return b[n] ^ 1;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= 2 * n - 1; ++i) scanf("%d", &a[i]);
	int l = 1, r = 2 * n - 1;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}