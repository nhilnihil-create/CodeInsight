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
char readc() {
	char c=getchar();
	while (c!='-'&&c!='+') c=getchar();
	return c;
}

const int N=100000+10;

int n;
ll dp[N][3];

int main() {
	n=read();
	dp[1][0]=read(),dp[1][1]=dp[1][2]=-1e18;
	for (int i=2;i<=n;++i) {
		char op=readc(); int w=read();
		if (op=='+') {
			dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+w;
			dp[i][1]=max(dp[i-1][1],dp[i-1][2])-w;
			dp[i][2]=dp[i-1][2]+w;
		} else {
			dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})-w;
			dp[i][1]=max(max(dp[i-1][1],dp[i-1][2])+w,dp[i-1][0]-w);
			dp[i][2]=max(dp[i-1][1],dp[i-1][2])+w;
		}
	}
	printf("%lld\n",max({dp[n][0],dp[n][1],dp[n][2]}));
	return 0;
}