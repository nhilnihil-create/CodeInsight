#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000
#define MOD 1000000007
#define rint register int
#define gc() getchar()
inline int read(int r=0,int s=0,int c=gc()){for(;c<48||c>57;s=c,c=gc());for(;c>=48&&c<=57;(r*=10)+=c-48,c=gc());return s^'-'?r:-r;}
inline int fxp(int s, int n=MOD-2){int a=1; for(; n; n&1 ? a = 1ll*a*s%MOD : 0, s = 1ll*s*s%MOD, n >>= 1); return a;}
int fac[4002005], efac[4002005], f[MAXN+5][MAXN+5], n, m, N; inline int C(int n, int k){return n<0||k<0||n<k?0:1ll*fac[n]*efac[k]%MOD*efac[n-k]%MOD;}
int main()
{
	n = read(), m = read(), N = n*m; if(m==1||n==1) return puts("1"),0; for(rint i = fac[0] = 1; i <= N; fac[i] = 1ll*i*fac[i-1]%MOD, i++);
	efac[N] = fxp(fac[N]); for(rint i = N; i; efac[i-1] = 1ll*i*efac[i]%MOD, i--); f[0][0] = 1;
	for(rint i = 0, j; i <= n; i++) for(j = i; j <= n; j++)
		f[i+1][j] = (f[i+1][j]+f[i][j])%MOD, f[i][j+1] = (f[i][j+1]+1ll*C(i+j*(m-1)+m-2,m-2)*f[i][j])%MOD;
	printf("%d\n",1ll*fac[n]*f[n][n]%MOD); return 0;
}