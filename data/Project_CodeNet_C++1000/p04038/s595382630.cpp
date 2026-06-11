#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int f[2010][2010];
int inv[4001000],C[4001000];
int main(){
	int n=gi(),k=gi();
	if(k==1)return puts("1"),0;
	inv[1]=1;for(int i=2;i<=n*k;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	C[k-2]=1;
	for(int i=k-1;i<=n*k;++i)C[i]=1ll*C[i-1]*inv[i-k+2]%mod*i%mod;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=std::min(i,n);++j){
			f[i][j]=f[i-1][j];
			if(j)f[i][j]=(f[i][j]+1ll*C[(n-i)+(n-j+1)*(k-1)-1]*f[i][j-1]%mod*(n-j+1)%mod)%mod;
		}
	printf("%d\n",f[n][n]);
	return 0;
}
