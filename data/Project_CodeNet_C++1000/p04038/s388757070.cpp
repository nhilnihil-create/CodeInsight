#include <bits/stdc++.h>
using namespace std;
const int N=2002,M=1e9+7;
int n,m,k,f[N*N],F[N*N],g[N][N];
int mi(int a,int b){
	int s=1;
	for(;b;b>>=1,a=1LL*a*a%M)if(b&1)s=1LL*s*a%M;
	return s;
}
int main(){
	cin>>n>>k;m=n*k;
	if(k==1){puts("1");return 0;}
	f[0]=1;
	for(int i=1;i<=m;++i)f[i]=1LL*f[i-1]*i%M;
	F[m]=mi(f[m],M-2);
	for(int i=m;i>=1;--i)F[i-1]=1LL*F[i]*i%M;
	g[0][0]=1;
	for(int i=0,I=k-1;i<=n;++i,I+=k-1)for(int j=0;j<=i;++j){
		(g[i+1][j]+=1LL*g[i][j]*f[I+j-1]%M*F[I+j-k+1]%M*F[k-2]%M)%=M;
		(g[i][j+1]+=g[i][j])%=M;
	}
	cout<<1LL*g[n][n]*f[n]%M<<endl;
}