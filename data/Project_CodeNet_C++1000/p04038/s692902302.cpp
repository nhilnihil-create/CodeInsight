#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
//{{{ read()
inline ll read(){
	register ll x=0,f=1;
	register char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')	x=x*10+(ch^48),ch=getchar();
	return x*f;
}
//}}}
const int N=2005;
const int M=4e6+5;
const int P=1e9+7;
ll fsp(ll x,int y=P-2){
	ll ans=1;
	while(y){
		if(y&1)	ans=ans*x%P;
		x=x*x%P,y>>=1;
	}
	return ans;
}
int n,k,m,f[N];
ll fac[M],inv[M];
ll C(int n,int m){
	if(n>M)	return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read(),m=n*k,fac[0]=1;
	if(k==1){
		puts("1");
		return 0;
	}
	for(int i=1;i<=m;i++) fac[i]=fac[i-1]*i%P;
	inv[m]=fsp(fac[m]);
	for(int i=m;i;i--) inv[i-1]=inv[i]*i%P;

	f[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j;j--)
			f[j]=(f[j-1]+f[j+1]*C(m-i-(k-1)*(i-j-1)-1,k-2))%P;
		f[0]=f[1]*C(m-i-(k-1)*(i-1)-1,k-2)%P;
	}
	printf("%lld\n",f[0]*fac[n]%P);
	return 0;
}
