#include<cstdio>
#define N 1000005
#define MOD 1000000007
using namespace std;
namespace runzhe2000
{
	int n; long long ans, f[N], pre;
	void main()
	{
		scanf("%d",&n);
		f[0] = pre = 1;
		for(int i = 0; i <= n; i++)
		{
			if(i)
			{
				(f[i] += pre) %= MOD;
				if(i-2>=0)(f[i] -= f[i-2]) %= MOD;
				(pre += f[i]) %= MOD;
			}
			if(i<=n-2)(ans += f[i] * (n-1) % MOD * (n-1)) %= MOD;
			if(i<=n-2)(ans += f[i] * (i+1)) %= MOD;
			if(i==n-1)(ans += f[i] * i) %= MOD;
			if(i==n)(ans += f[i]) %= MOD;
		}
		printf("%lld\n",(ans+MOD)%MOD);
	}
}
int main()
{
	runzhe2000::main();
}