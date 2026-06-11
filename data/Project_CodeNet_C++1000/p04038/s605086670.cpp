#include<bits/stdc++.h>
#define IL inline
#define RG register
#define LL long long
#define Upd(a) (a)>=mod?(a-=mod):1
using namespace std;
template <class T>
IL char gc () {
	static char buf[1<<6], *p1=buf, *p2=buf;
	return (p1==p2) && (p2=(p1=buf)+fread(buf,1,1<<6,stdin), p1==p2) ?EOF:*p1++;
}
template <typename T>
IL void read (T&data) {
	data=0;
	RG char ch=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch<='9' && ch>='0') data=(data<<1)+(data<<3)+(ch&15), ch=getchar();
}
const int mod = 1e9+7;
const int _ =2011;
int n, k;
int dp[2][_], jc[_*_], jcn[_*_];
IL int poww (RG int a, RG int b) {
	RG int ret=1, Base=a;
	for (;b;b>>=1, Base=1LL*Base*Base%mod) if (b&1) ret=1LL*ret*Base%mod;
	return ret;
}
IL int C (RG int a, RG int b) {
	if (a<b) return 0;
	return 1LL*jc[a]*jcn[b]%mod*jcn[a-b]%mod;
}
int main (/*int aa, int bb*/) {
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	//n=aa, k=bb;
	read(n), read(k);
	if (k<=1) {puts("1"); return 0;}
	jc[0]=jcn[0]=1;
	RG int i, j, pre=1, cur=0;
	for (i=1; i<=n*k; ++i) jc[i]=1LL*jc[i-1]*i%mod, jcn[i]=poww(jc[i], mod-2);
	dp[0][0]=1;
	for (i=1; i<=n*2; ++i) {
		swap(cur, pre);
		for (j=0; j<min(i,n+1); ++j) dp[cur][j]=0;
		for (j=1; j<=min(i,n); ++j) {
			if ((i-j)%2) continue;
			if (n*2-i+1<j) break;
			RG int a=(i+j-2)>>1, b=(i-j)>>1;
			dp[cur][j]=1LL*dp[pre][j-1]*C(a*(k-1)+b+k-1-1,k-1-1)%mod;
			dp[cur][j]+=dp[pre][j+1];
			Upd(dp[cur][j]);
		}
		if (cur%2==0) dp[cur][0]=dp[pre][1];
	}
	//return 1LL*dp[cur][0]*jc[n]%mod;
	printf("%lld",1LL*dp[cur][0]*jc[n]%mod);
}
