// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=1000000+10;
const int mod=1e9+7;

int n,dp[N];

int main() {
	n=read();
	if (n==1) { puts("1"); return 0; }
	dp[n]=n,dp[n-1]=1ll*n*n%mod;
	for (int i=n-2,s=0;i;--i) {
		dp[i]=(s+i+1+1ll*(n-1)*(n-1)+dp[i+1])%mod;
		s=(s+dp[i+2])%mod;
	}
	printf("%d\n",dp[1]);
	return 0;
}