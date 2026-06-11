#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2005;
const int maxf=4e6+5;
const LL mo=1e9+7;
int n,k;
LL F[maxn][maxn],fac[maxf],inv[maxf];
LL kpow(LL x,LL y,LL p)
{
	LL s=1LL;
	while(y){
		if((y&1LL)) s=s*x%p;
		x=x*x%p;
		y>>=1;
	}
	return s;
}
LL C(int x,int y)
{
	if(x<y||y<0) return 0;
	if(!y||x==y) return 1LL;
	return (fac[x]*inv[y]%mo)*inv[x-y]%mo;
}
void pre()
{
	fac[0]=1LL;
	for(int i=1;i<=n*k;++i) fac[i]=fac[i-1]*i%mo;
	inv[n*k]=kpow(fac[n*k],mo-2,mo);
	for(int i=n*k-1;i>=1;--i) inv[i]=inv[i+1]*(i+1)%mo;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) F[i][0]=1;
	if(k==1) printf("1");
	else{
		pre();
		//cout<<C(1,1);
		for(int i=1;i<=n;++i)
		  for(int j=1;j<=i;++j){
		  	LL s=F[i][j-1]*(n-j+1)%mo;
		  	s=s*C(n*k-i-(j-1)*(k-1)-1,k-2)%mo;
		  	F[i][j]=(F[i-1][j]+s)%mo;
		  	//cout<<i<<" "<<j<<" "<<F[i][j]<<" "<<F[i-1][j]<<" "<<F[i][j-1]<<endl;
		  	//cout<<(n*k-i-(j-1)*(k-1)-1)<<" "<<k-2<<" "<<C(n*k-i-(j-1)*(k-1)-1,k-2)<<endl;
		  }
		printf("%lld",F[n][n]);
	}
	return 0;
}