#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int INF = 1e9;
int a[maxn], l[maxn], r[maxn];
ll ans;
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	stack<int> s; s.push(0);
	for(int i = 1; i <= n; ++i)
	{
		while(a[s.top()] > a[i]) s.pop();
		l[i] = s.top();
		s.push(i);
	}
	stack<int>().swap(s); s.push(n + 1);
	for(int i = n; i; --i)
	{
		while(a[s.top()] >= a[i]) s.pop();
		r[i] = s.top();
		s.push(i);
	}
	for(int i = 1; i <= n; ++i)
		ans += 1ll * a[i] * (r[i] - i) * (i - l[i]);
	printf("%lld\n", ans);
	return 0;
}
	