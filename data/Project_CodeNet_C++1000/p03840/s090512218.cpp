#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll a[7];
int main()
{
	for (int i = 0; i < 7; i++)
		scanf("%lld", &a[i]);
	ll dap = a[1] * 2;
	ll update = 0;
	if (a[0] > 0&&a[3]>0&&a[4]>0)
	{
		update = 6 + ((a[0] - 1) / 2 * 4) + (a[3] - 1) / 2 * 4 + (a[4] - 1) / 2 * 4;
	}
	dap = dap + max(update, a[0] / 2 * 4 + a[3] / 2 * 4 + a[4] / 2 * 4);
	printf("%lld", dap/2);
}