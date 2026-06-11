#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main()
{
	int num;
	scanf("%d", &num);
	ll ans = 1;
	int cnt = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		cnt++;
		if (cnt * 2 - 1 > z)
		{
			ans *= cnt;
			ans %= mod;
			cnt--;
		}
	}
	for (int i = 1; i <= cnt; i++)ans = ans*i%mod;
	printf("%lld\n", ans);
}