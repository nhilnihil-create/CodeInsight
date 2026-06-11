#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d", &num);
	ll ans = 0;
	ll now = 2;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (i == 0)ans += z - 1;
		else if (z == now)now++;
		else ans += (z - 1) / now;
	}
	printf("%lld\n", ans);
}