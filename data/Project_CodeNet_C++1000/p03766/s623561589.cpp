#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

const int maxn = 1000010;
const int mod = 1000000007;

ll f[maxn], sum[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	f[1] = sum[1] = n;
	for (int i=2;i<=n;i++)
	{
		f[i] = f[i-1] + (ll)(n-1) * (ll)(n-1);
		if (i>1) f[i] += (ll)(n - max(2,i-1) + 1);
		if (i>3) f[i] += sum[i-3];
		f[i] %= mod;
		sum[i] = (sum[i-1] + f[i]) % mod;
	}
	printf("%lld\n",f[n]%mod);
	return 0;
}
