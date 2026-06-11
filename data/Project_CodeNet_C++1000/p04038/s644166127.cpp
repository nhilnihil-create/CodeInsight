#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=2000*2000+10;
int n,k;
ll iv[maxn],ivjc[maxn];
ll dp[2010][2010],jc[maxn];
ll C(int x,int y) {
	return jc[x]*ivjc[y]%mod*ivjc[x-y]%mod;
}
ll ksm(ll x,int y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(k);
	if (k==1) { printf("1\n"); return 0; }
	iv[0]=jc[0]=ivjc[0]=1;
	iv[1]=jc[1]=ivjc[1]=1;
	for (int i=2;i<=n*k;i++)
		jc[i]=jc[i-1]*i%mod;
	ivjc[n*k]=ksm(jc[n*k],mod-2);
	for (int i=n*k-1;i>=2;i--)
		ivjc[i]=ivjc[i+1]*(i+1)%mod;
	dp[0][0]=1;
	for (int i=1;i<=n;i++)
	for (int j=i;j>=0;j--)
		dp[i][j]=(dp[i-1][j-1]*C(k*i-j-1,k-2)+dp[i][j+1])%mod;
	printf("%lld\n",dp[n][0]*jc[n]%mod);
	return 0;
}