#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 10;
ll a, b, c, s;
int f(ll x)
{
	if(x & 1) return 0;
	return f(s - x / 2) + 1;
}
int main()
{
	cin >> a >> b >> c;
	if(a % 2 || b % 2 || c % 2)
	{
		puts("0");
		return 0;
	}
	s = (a + b + c) / 2;
	int ans = INF;
	if(3 * a / 2 != s) ans = min(ans, f(a));
	if(3 * b / 2 != s) ans = min(ans, f(b));
	if(3 * c / 2 != s) ans = min(ans, f(c));
	if(ans == INF) puts("-1");
	else printf("%d\n", ans);
	return 0;
}