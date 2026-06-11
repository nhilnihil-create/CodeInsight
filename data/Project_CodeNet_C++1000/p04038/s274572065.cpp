#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

typedef long long ll;

const int N=2333,NN=5e6;
const ll p=1e9+7;

int n,k;
ll jc[NN+3],njc[NN+3],f[N][N],g[N][N];

ll ksm(ll x,ll w){
	ll ans=1;
	while(w){
		if(w&1ll) (ans*=x)%=p;
		(x*=x)%=p;
		w>>=1;
	}
	return ans;
}

ll C(ll a,ll b){
	return (jc[a]*njc[b]%p)*njc[a-b]%p;
}

int main(){
	scanf("%d%d",&n,&k);

	if(k==1){
		printf("1\n");
		return 0;
	} 

	jc[0]=njc[0]=1;int L=5e6;
	rep(i,1,L) jc[i]=(jc[i-1]*i)%p;
	rep(i,1,L) njc[i]=ksm(jc[i],p-2);

	rep(j,1,n) g[n][j]=1;f[n][n]=1;
	per(i,n-1,1){
		rep(j,i,n)
			f[i][j]=(g[i+1][j]*C(n-j+(n-i+1)*(k-1)-1,k-2))%p;
		per(j,n,1) g[i][j]=(g[i][j+1]+f[i][j])%p;
	} 

	ll ans=0;
	rep(i,1,n) (ans+=f[1][i])%=p;
	(ans*=jc[n])%=p;

	printf("%lld\n",ans);

	return 0;
}