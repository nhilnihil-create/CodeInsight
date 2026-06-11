#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
long long f[2005][2005];
long long fac[5000005],inv[5000005];
int n,k;
long long qpow(long long a,long long b){
	b%=(mod-1);
	a=a%mod;
	long long ans=1;
	while(b){
		if(b&1)	ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=5000000;i++)	fac[i]=fac[i-1]*i%mod;
	inv[5000000]=qpow(fac[5000000],mod-2);
	for(int i=4999999;i>=1;i--)	inv[i]=inv[i+1]*(i+1)%mod;
}
long long C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}	
	f[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==0&&j==0)	continue;
			if(i)	f[i][j]=(f[i][j]+f[i-1][j])%mod;
			f[i][j]=(f[i][j]+f[i][j-1]*C(i+(j-1)*(k-1)+1+k-2-1,i+(j-1)*(k-1)+1-1)%mod)%mod;
		}
	}
	cout<<f[n][n]*fac[n]%mod<<endl;
}