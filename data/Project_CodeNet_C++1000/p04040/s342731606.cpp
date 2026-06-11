#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
const int mod=1e9+7,M=1e6+7;
LL read(){
	LL ans=0,f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+(c-'0'); c=getchar();}
	return ans*f;
}
LL n,m,A,B;
LL qmod(LL a,LL b){
	LL ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		b>>=1; a=a*a%mod;
	}
	return ans;
}
LL w[M],f[M];
void pre(){
	int mx=2e5; w[0]=1;
	for(int i=1;i<=mx;i++) w[i]=w[i-1]*i%mod;
	f[mx]=qmod(w[mx],mod-2);
	for(int i=mx;i>=1;i--) f[i-1]=f[i]*i%mod;
} 
LL C(LL n,LL m){return w[n]*f[n-m]%mod*f[m]%mod;}
LL F(int x,int y,int nx,int ny){
	int p=nx-x,q=ny-y;
	return C(p+q,q);
}
LL ans;
int main(){
	pre();
	n=read(); m=read(); A=read(); B=read();
	ans=F(1,1,n,m);
	for(int i=1;i<=B;i++){
		int sum=F(1,1,n-A,i)*F(n-A+1,i,n,m)%mod;
		ans=(ans-sum)%mod;
		ans=(ans+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}