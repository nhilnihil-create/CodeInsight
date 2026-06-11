#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005, P=1000000007;
int f[N][N], fac[N*N], ifac[N*N];

int C(int n, int m){return fac[n]*ifac[m]%P*ifac[n-m]%P;}
int Pow(int x, int t)
{
	int res=1;
	while (t) {if (t&1) res=res*x%P; x=x*x%P; t>>=1;}
	return res;
}

signed main()
{
	int n, k; scanf("%d%d", &n, &k);
	if (k==1) {puts("1"); return 0;}
	f[0][0]=fac[0]=1; 
	for (int i=1; i<=4e6; i++) fac[i]=fac[i-1]*i%P; 
	ifac[(int)4e6]=Pow(fac[(int)4e6], P-2);
	for (int i=4e6-1; ~i; i--) ifac[i]=ifac[i+1]*(i+1)%P;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=i; j++)
			f[i][j]=f[i-1][j]+(j!=0)*
				(f[i][j-1]*(n-j+1)%P*C(n*k-i-(j-1)*(k-1)-1, k-2)%P)%P;
	printf("%d\n", f[n][n]);
	return 0;
}
