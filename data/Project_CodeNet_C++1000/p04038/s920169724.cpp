#include <bits/stdc++.h>
#define ll long long
const int md=1e9+7;
const int maxm=4001000;
const int maxn=2001;
int read(){
	int x=0,flag=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if (ch=='-') flag=-1,ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
	return x*flag;
}
ll fac[maxm],inv[maxm];
ll ksm(ll a,ll b){
	ll res=1;
	while(b){
		if (b&1) res=res*a%md;
		a=a*a%md;b>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=1;
	for (int i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%md;
	inv[n]=ksm(fac[n],md-2);
	for (int i=n;i;--i)
		inv[i-1]=inv[i]*i%md;
}
ll c(int n,int m){
	return fac[n]*inv[m]%md*inv[n-m]%md;
}
int n,k,f[maxn][maxn];
int main(){
	n=read(),k=read();
	if (k==1) return puts("1"),0;
	init(n*k);
	f[0][0]=1;
	for (int i=1;i<=n;++i){
		for (int j=0;j<=i;++j){
			f[i][j]=f[i-1][j];
			if (!j) continue;
			(f[i][j]+=1ll*f[i][j-1]*(n-j+1)%md*
			c(n-i+(n-j+1)*(k-1)-1,k-2)%md)%=md;
		}
	}
	printf("%d\n",f[n][n]);
}