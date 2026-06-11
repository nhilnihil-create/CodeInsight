#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 2010
inline int Pow(int x,int zs){
	int ret=1;
	for(;zs;zs>>=1,x=x*1ll*x%mod)
		if(zs&1)ret=ret*1ll*x%mod;
	return ret;
}
int f[N][N],n,k,A[10000010],B[10000010];
inline int C(int n,int m){
	if(m>n||m<0)return 0;
	if(n==m||m==0)return 1;
	return A[n]*1ll*B[m]%mod*B[n-m]%mod;
}
int main(){
	n=1e7;
	for(int i=A[0]=1;i<=n;i++)A[i]=A[i-1]*1ll*i%mod;
	B[n]=Pow(A[n],mod-2);
	for(int i=n-1;~i;i--)B[i]=B[i+1]*(i+1ll)%mod;
	scanf("%d%d",&n,&k);
	if(k==1)return puts("1"),0;
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(i)f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+f[i][j-1]*1ll*C(i+(j-1)*(k-1)+(k-2),k-2))%mod;
		}
	printf("%lld\n",f[n][n]*1ll*A[n]%mod);
	return 0;
}
