#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
const int N=2005;
long long f[N][N],fac[N*N],inv[N*N];
long long fsp(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1)	ans=ans*x%P;
		x=x*x%P,y>>=1;
	}
	return ans;
}
long long C(int n,int m){
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
int n,m,k;
int main(){
	scanf("%d%d",&n,&k),m=n*k;
	fac[0]=inv[0]=f[0][0]=1;
	for(int i=1;i<=m;i++){
		fac[i]=fac[i-1]*i%P;
		inv[i]=fsp(fac[i],P-2);
	}
	if(k==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=i;j++)
			f[i][j]=(f[i][j-1]*C(m-i-(j-1)*(k-1)-1,k-2)%P*(n-j+1)+f[i-1][j])%P;
	printf("%lld\n",f[n][n]);
	return 0;
}