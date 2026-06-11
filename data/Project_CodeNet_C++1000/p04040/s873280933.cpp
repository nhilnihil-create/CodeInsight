#include<iostream>
#define N 200000
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL fac[N+1];
LL fac_inv[N+1];
LL mod_pow(LL base, LL exp)
{
	if(exp==0) return 1;
	if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
	else return mod_pow((base*base)%MOD,exp/2);
}
LL C(LL n, LL k)
{
	if(k < 0 || n < k) return 0;
	LL num = fac[n];
	LL den = (fac_inv[k]*fac_inv[n-k])%MOD;
	return (num*den)%MOD;
}
LL paths(LL h, LL w)
{
	return C(h-1+w-1,h-1);
}
int main()
{
	fac[0] = 1;
	for(LL n = 1; n <= N; n++)
		fac[n] = (fac[n-1]*n)%MOD;
		
	fac_inv[N] = mod_pow(fac[N],MOD-2);
	for(LL n = N-1; n >= 0; n--)
		fac_inv[n] = (fac_inv[n+1]*(n+1))%MOD;
		
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	LL h, w, a, b; cin >> h >> w >> a >> b;
	
	LL ans = 0;
	for(LL i = h-a, j = b+1; i > 0 && j <= w; i--, j++)
		ans = (ans+paths(i,j)*paths(h-i+1,w-j+1))%MOD;
	cout<<ans<<endl;
	
	return 0;
}