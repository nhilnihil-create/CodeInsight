#include<cstdio>
#define ll long long
const int N=2005,M=4e6+5,mo=1e9+7;
int n,m,nm,i,j,f[N];
int fact[M],inv[M],fv[M];
void init(int n){
	fact[0]=fact[1]=inv[1]=fv[0]=fv[1]=1;
	for (i=2;i<=n;i++){
		fact[i]=(ll)fact[i-1]*i%mo;
		inv[i]=(ll)inv[mo%i]*(mo-mo/i)%mo;
		fv[i]=(ll)fv[i-1]*inv[i]%mo;
	}
}
int C(int n,int m){return (ll)fact[n]*fv[m]%mo*fv[n-m]%mo;}
/*
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
testtesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttesttetesttesttest
*/
int main(){
	scanf("%d%d",&n,&m);m--;
	if (!m){puts("1");return 0;}
	nm=n*m+n;init(nm);f[0]=1;
	for (i=1;i<=n;i++) for (j=1;j<=i;j++)
		f[j]=(f[j]+(ll)C(nm-i-(j-1)*m-1,m-1)%mo*f[j-1])%mo;
	for(int i=1;i<=n;i++)f[n]=1ll*f[n]*i%mo;
	printf("%d",f[n]);
}
