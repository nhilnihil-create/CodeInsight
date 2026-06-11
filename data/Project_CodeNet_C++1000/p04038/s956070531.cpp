#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long

using namespace std;

const int N=4000100,mod=1e9+7;
int n,k,fac[N],inv[N],f[2100][2100],ans;

int ksm(int x,int y){
	int s=1;
	for (;y;y>>=1,x=(ll)x*x%mod) if (y&1) s=(ll)s*x%mod;
	return s;
}

void init(int n){
	fac[0]=1;
	rep (i,1,n) fac[i]=(ll)fac[i-1]*i%mod;
	inv[n]=ksm(fac[n],mod-2);
	for (int i=n-1;~i;i--) inv[i]=(ll)inv[i+1]*(i+1)%mod;
}

int C(int n,int m){return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;}

void upd(int &x,int y){x+=y; x-=x>=mod?mod:0;}

int main(){
	scanf("%d%d",&n,&k); init(n*k+1);
	if (k==1) return puts("1"),0;
	f[0][0]=1;
	rep (i,0,n) rep (j,0,i){
		if (i==n&&j==n){
			printf("%lld\n",(ll)f[n][n]*fac[n]%mod);
			break;
		}
		if (i<n) upd(f[i+1][j],f[i][j]);
		if (j<n) upd(f[i][j+1],(ll)f[i][j]*C(n*k-i-j*(k-1)-1,k-2)%mod);
	}
	return 0;
}