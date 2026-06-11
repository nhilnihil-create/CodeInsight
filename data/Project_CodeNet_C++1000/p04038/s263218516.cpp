#include <bits/stdc++.h>
using namespace std;

#define fo(i,s,t) for(int i = s; i <= t; ++ i)
#define fd(i,s,t) for(int i = s; i >= t; -- i)
#define bf(i,s) for(int i = head[s]; i; i = e[i].next)
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define pb push_back
#define VI vector<int>
#define sf scanf
#define pf printf
#define fp freopen
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
const int inf = 1<<30;
const ll INF = 1ll<<60;
const db Inf = 1e20;
const db eps = 1e-9;

void gmax(int &a,int b){a = (a > b ? a : b);}
void gmin(int &a,int b){a = (a < b ? a : b);}

const int maxn = 4000050;
const int maxm = 2005;
const int P = 1e9+7;

int n, k, dp[maxm][maxm], fac[maxn], infr[maxn];

ll comb(int n,int m) {return 1ll*fac[n]*infr[m]%P*infr[n-m]%P;}
int qpow(int a,int b) {int ans = 1; while(b) {if(b&1) ans = (ans*1ll*a)%P; b >>= 1; a = (a*1ll*a)%P;} return ans;}
void upd(int &x,int y) {x += y; if(x > P) x -= P;}
int main()
{
	#ifdef MPS
		fp("agc02f.in","r",stdin);
		fp("agc02f.out","w",stdout);
	#endif
	sf("%d%d",&n,&k);
	fac[0] = 1; fo(i,1,n*k) fac[i] = (fac[i-1]*1ll*i)%P;
	infr[n*k] = qpow(fac[n*k],P-2);
	fd(i,n*k-1,0) infr[i] = infr[i+1]*1ll*(i+1)%P;
	if(k == 1) return 0*pf("1\n");
	dp[0][0] = 1;
	fo(i,0,n) fo(j,0,n)
	{
		if(i < j) upd(dp[i+1][j],dp[i][j]);
		if(j < n) dp[i][j+1] = (dp[i][j+1] + (1ll * dp[i][j] * comb(j*k-j+i+k-2,k-2)) % P) % P;
	}
	pf("%lld\n",(1ll*dp[n][n]*fac[n])%P);
	return 0;
}
