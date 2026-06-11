#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Forr(i,j,k) for(int i=j;i>=k;--i)
#define ll long long 
using namespace std;
const int N = 2010, INF = 0x3f3f3f3f, Mod = 1e9 + 7;
template<class T>void read(T &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while( isdigit(c))x=x*10+c-48,c=getchar();
}
inline void file(){
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
}
int n, k, fac[N * N], ifac[N * N];
ll qpow(ll a, ll b){
	ll ret=1;
	for(;b;b>>=1,a=a*a%Mod)if(b&1)ret=ret*a%Mod;
	return ret;
}
void init(){
	read(n), read(k);
	fac[0] = 1;
	For(i, 1, n * k)fac[i] = 1ll * fac[i - 1] * i % Mod;
	ifac[n * k] = qpow(fac[n * k], Mod - 2);
	Forr(i, n * k, 1)ifac[i - 1] = 1ll * ifac[i] * i % Mod;
}
inline ll C(int a, int b){
	if(a < 0 || b < 0 || a < b)return 0;
	return fac[a] * 1ll * ifac[b] % Mod * ifac[a - b] % Mod;
}
int dp[N][N];
void solve(){
	dp[0][0] = 1;
	For(i, 0, n)
		For(j, i, n){
			if(i) dp[i][j] = dp[i - 1][j];
			if(j) dp[i][j] = (dp[i][j] + dp[i][j - 1] * C(i + j * (k - 1) - 1, k - 2)) % Mod;
		}
	if(k != 1)
		printf("%lld\n", 1ll * dp[n][n] * fac[n] % Mod);
	else puts("1");
}
int main(){
	//file();
	init();
	solve();
	return 0;
}
