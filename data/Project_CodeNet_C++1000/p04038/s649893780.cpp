//Code by Enderturtle
#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define repe(i,a) for(register int i=head[a];i;i=e[i].nxt)
#define il inline
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;
il void filejudge(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
il int read(){
	int x=0;bool f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=0;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?x:-x;
}
/*----- head end -----*/
const int N=2010,mod=1e9+7;
ll fac[N*N],inv[N*N];

il ll ksm(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
il void init(){
	const int ed=2000*2000;
	fac[0]=1;
	rep(i,1,ed) fac[i]=fac[i-1]*i%mod;
	inv[ed]=ksm(fac[ed],mod-2);
	for(register int i=ed-1;i>=1;--i) inv[i]=inv[i+1]*(i+1ll)%mod;
	inv[0]=1;
}
il ll c(int x,int y){ return fac[x]*inv[y]%mod*inv[x-y]%mod;}

ll dp[N][N];
int n,k;

il void add(ll &x,ll y){
	x+=y;
	if(x>=mod) x-=mod;
}

int main(){
	init();
	n=read();k=read();
	if(k==1){puts("1");return 0;}
	dp[0][0]=1;
//	rep(i,1,n*n) cerr<<fac[i]<<' '<<inv[i]<<endl;
	rep(i,0,n-1){
		rep(j,i,n){
			if(dp[i][j]){
				if(i<j) add(dp[i+1][j],dp[i][j]);
				if(j<n) add(dp[i][j+1],c(i+j*(k-1)+k-2,k-2)*dp[i][j]%mod);
			//	cerr<<i+j*(k-1)+k-1<<' '<<k-1<<endl;
			}
		}
	}
	printf("%lld\n",dp[n][n]*fac[n]%mod);
	return 0;
}