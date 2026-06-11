#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 1000000007
#define MAXN 2005

template <typename T> inline void read (T &t){t = 0;char c = getchar();int f = 1;while (c < '0' || c > '9'){if (c == '-') f = -f;c = getchar();}while (c >= '0' && c <= '9'){t = (t << 3) + (t << 1) + c - '0';c = getchar();} t *= f;}
template <typename T,typename ... Args> inline void read (T &t,Args&... args){read (t);read (args...);}
template <typename T> inline void write (T x){if (x < 0){x = -x;putchar ('-');}if (x > 9) write (x / 10);putchar (x % 10 + '0');}

int n,k,fac[MAXN * MAXN],ifac[MAXN * MAXN],dp[MAXN][MAXN];
int mul (int a,int b){return 1ll * a * b % mod;}
int dec (int a,int b){return a >= b ? a - b : a + mod - b;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
int qkpow (int a,int b){int res = 1;for (;b;b >>= 1,a = mul (a,a)) if (b & 1) res = mul (res,a);return res;}
int binom (int a,int b){return mul (fac[a],mul (ifac[b],ifac[a - b]));}

signed main(){
	read (n,k);
	if (k == 1) return puts ("1"),0;fac[0] = 1;
	for (Int i = 1;i <= n * k;++ i) fac[i] = mul (fac[i - 1],i);
	ifac[n * k] = qkpow (fac[n * k],mod - 2);for (Int i = n * k;i;-- i) ifac[i - 1] = mul (ifac[i],i);
	for (Int i = 0;i <= n;++ i) dp[i][0] = 1;
	for (Int i = 1;i <= n;++ i)
		for (Int j = 1;j <= i;++ j)
			dp[i][j] = add (dp[i - 1][j],mul (dp[i][j - 1],binom (n * k - (k - 1) * (j - 1) - 1 - i,k - 2)));
	write (mul (dp[n][n],fac[n])),putchar ('\n');
	return 0;
}
/*
dp[i][j]表示前面i个白球，j个颜色已经填满了
dp[i][j]=dp[i-1][j]+dp[i][j-1]*C(n*k-(k-1)*(j-1)-1-i,k-2) 
dp[n][n]*n!
*/