#include<iostream>
#define N 1000000
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL f[N+1];
LL solve()
{
	LL n; cin >> n;

	f[0] = 1;
	f[1] = n;
	f[2] = (n*n)%MOD;
	
	LL running_sum = (n*n+n+1)%MOD;
	for(LL k = 3; k <= n; k++)
	{
		f[k] = (running_sum-f[k-2]+(n*n-n-k+2))%MOD;
		running_sum += f[k], running_sum %= MOD;
	}
	return (f[n]+MOD)%MOD;
}
int main()
{
	cout<<solve()<<endl;
	return 0;
}