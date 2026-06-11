#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll tot;
ll a[maxn], b[maxn];
void no() { puts("NO"); exit(0);}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%lld", &a[i]);
		tot += a[i];
	}
	ll per = 1ll * n * (n + 1) / 2;
	if(tot % per) no();
	tot /= per;
	a[0] = a[n];
	for(int i = 1; i <= n; ++i) 
	{
		b[i] = tot - (a[i] - a[i - 1]);
		if(b[i] < 0 || b[i] % n) no();
	}
	puts("YES");
	return 0;
}