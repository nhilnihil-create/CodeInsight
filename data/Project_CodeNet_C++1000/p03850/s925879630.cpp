#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll dp[maxn][3];
char op[maxn][10];
int a[maxn];
int n;
ll f(int i, int j)
{
	if(~dp[i][j]) return dp[i][j];
	ll ret = a[i] * ((j & 1) ? -1 : 1);
	if(i == n) return dp[i][j] = ret;
	if(op[i][0] == '+')
	{
		if(j > 0) ret += max(f(i + 1, j - 1), f(i + 1, j));
		else ret += f(i + 1, j);
		return dp[i][j] = ret;
	}
	else
	{
		if(j == 0) ret += f(i + 1, j + 1);
		else if(j == 1) ret += max(f(i + 1, j), f(i + 1, j + 1));
		else ret += f(i + 1, j);
		return dp[i][j] = ret;
	}
}
int main()
{
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	scanf("%d", &a[1]);
	for(int i = 2; i <= n; ++i) scanf("%s%d", op[i - 1], &a[i]);
	printf("%lld\n", f(1, 0));
	return 0;
}