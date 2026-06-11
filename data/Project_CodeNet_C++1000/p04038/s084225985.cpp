#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
#define SIZE 5000000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll dp[2001][2001];
int main()
{
	invinit();
	int num, k;
	scanf("%d%d", &num, &k);
	if (k == 1)
	{
		printf("1\n");
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= num; i++)
	{
		ll sum = 0;
		for (int j = i; j >= 1; j--)
		{
			sum = (sum + dp[i - 1][j - 1]) % mod;
			dp[i][j] = sum*com(i*k - j - 1, k - 2) % mod;
		}
	}
	ll ans = 0;
	for (int i = 0; i <= num; i++)ans = (ans + dp[num][i]) % mod;
	for (int i = 1; i <= num; i++)ans = ans*i%mod;
	printf("%lld\n", ans);
}