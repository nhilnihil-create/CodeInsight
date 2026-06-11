#define FILEIO(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout);
#include <stdio.h>
#include <string.h>
#define N 5005
#define CLZ 1000000007
typedef long long ll;
int n,m,f[N][N];char s[N];
inline ll qpow(ll a,int b) {
	ll ans=1;
	for(;b;b>>=1) {
		if(b&1) ans=ans*a%CLZ;
		a=a*a%CLZ;
	}
	return ans;
}
int main() {
	//FILEIO("keyboard");
	int i,j,k,*cur,*nxt;
	scanf("%d%s",&n,s);
	m=strlen(s);f[0][0]=1;
	for(i=0;i<n;++i) {
		cur=f[i];nxt=f[i+1];
		for(j=0;j<=i;++j) {
			nxt[j+1]=(nxt[j+1]+(cur[j]<<1))%CLZ;
			k=j?j-1:0;
			nxt[k]=(nxt[k]+cur[j])%CLZ;
		}
	}
	printf("%d",int(f[n][m]*qpow(qpow(2,m),CLZ-2)%CLZ));
	return 0;
}