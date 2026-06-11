#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define gc getchar
#define pc putchar
inline ll rd(){
    ll x=0,f=1;char c=gc();
    for(;!isdigit(c);c=gc())if(c=='-')f=-1;
    for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
    return x*f;
}
void write(ll x){if(x<0)x=-x,pc('-');if(x>=10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int mod = 1e9+7;
const int maxn = 2099;
int dp[maxn][maxn],fac[maxn*maxn],inv[maxn*maxn],n,k;
inline int C(int n,int m){
	return 1ll * fac[n] * inv[m] % mod * inv[n-m] % mod;
}
inline int qpow(int a,int b){
	int ans = 1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)ans=1ll*ans*a%mod;
	return ans; 
}
int main(){
	n = rd(),k = rd();
	if(k==1){puts("1");return 0;}
	fac[0] = 1;
	Rep(i,1,2002*2002) fac[i] = 1ll * fac[i-1] * i % mod;
	inv[2002*2002] = qpow(fac[2002*2002],mod-2);
	Dep(i,2002*2002-1,0) inv[i] = 1ll * inv[i+1] * (i+1) % mod;
	dp[0][1] = 1;
	Rep(i,2,n){
		dp[0][i] = 1ll * dp[0][i-1] * C((i-1)*(k-1) + k-2,k-2) % mod;
		//n插入m 
	}
	Rep(i,1,n){
		Rep(j,i,n){
			dp[i][j] = (dp[i-1][j] +
			1ll * dp[i][j-1] * C(i+(j-1)*(k-1)+k-2,k-2) % mod) % mod;
		}
	}
	writeln(1ll * dp[n][n] * fac[n] % mod);
	return 0;
}
//n+1个空 
//a1 + a2 + a3 …… an + a[n+1] = m
//(a1+1) + (a2+1) + (a3+1) + …… = m + n + 1