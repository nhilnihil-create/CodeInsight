#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2100;
#define mod 1000000007
int i,j,k,n,m,x,y,t;
ll fac[N*N],inv[N*N],f[N][N];
ll c(int x,int y){ return fac[x]*inv[y]%mod*inv[x-y]%mod; }
int read(){ int x=0,f=1;char ch=getchar(); for (;!isdigit(ch);ch=getchar()) if (ch=='-')  f=-f; for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0'; return x*f; }
int main(){
	n=read();k=read();f[n][n]=1;
	if (k==1) {printf("1\n");return 0;}
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<N*N;i++) fac[i]=fac[i-1]*i%mod;
	for (int i=2;i<N*N;i++) inv[i]=-(mod/i)*inv[mod%i]%mod;
	for (int i=2;i<N*N;i++) inv[i]=inv[i-1]*(inv[i]+mod)%mod;
	for (int i=n;i>=0;i--) for (int j=i;j>=0;j--){ f[i][j]=(f[i][j]+f[i+1][j])%mod; if (i>j) f[i][j]=(f[i][j]+f[i][j+1]*c((n-j)*k-(i-j)-1,k-2))%mod; }
	printf("%lld\n",f[0][0]*fac[n]%mod);
	return 0;
}