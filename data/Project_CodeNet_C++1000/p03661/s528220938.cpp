#include<stdio.h>
#include<math.h>
#include<algorithm> 
using namespace std;
long long a[200005] = {0}, i, n, m, ans= 99000000000;
int main()
{
	scanf("%lld", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lld", &m);
		a[i] = a[i - 1] + m;
	}
	for (i = 1; i<n; i++)ans = min(abs(a[i] * 2 - a[n]), ans);
	printf("%lld\n", ans);
	return 0;
}