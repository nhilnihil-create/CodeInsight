#include <cstdio>
#include <cstring>
#define MAXN 1000010
#define LL long long

const LL P=1000000007;

int n;
LL g[MAXN],sg[MAXN];

inline void update(LL &x,LL y){ x=(x+y)%P; }

int main(){
	scanf("%d",&n);
	g[0]=1;
	sg[0]=1;
	for(int i=1;i<=n;i++){
		g[i]=g[i-1];
		if(i>=3) g[i]=(g[i]+sg[i-3])%P;
		sg[i]=(sg[i-1]+g[i])%P;
	}
	LL ans=0;
	//a[n]=1
	update(ans,g[n-1]);
	for(int i=2;i<=n;i++){
		int j=n-i-1;
		if(j<0) j=0;
		update(ans,sg[n-2]-(j?sg[j-1]:0));
	}
	//a[n-1]=1
	update(ans,g[n-1]*(n-1));
	//else
	for(int i=0;i<=n-2;i++)
		update(ans,g[i]*(n-1)%P*(n-1));
	ans=(ans+P)%P;
	printf("%lld\n",ans);
}
