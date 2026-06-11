

#include<bits/stdc++.h>
const int MN=2000+5;
const int P=1000000007;
using namespace std;
typedef long long ll;
template<typename T>inline T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n,m;
int inv[MN*MN],fac[MN*MN],f[MN][MN];
int qp(int a,int b){int c=1;for(;b;b>>=1,a=(ll)a*a%P)if(b&1)c=(ll)c*a%P;return c;}
int C(int n,int m){return (ll)fac[n]*inv[m]%P*inv[n-m]%P;}
void input(){
	IN(n),IN(m);f[0][0]=fac[0]=1;
	if(m==1)return puts("1"),void();
	for(int i=1;i<=MN*MN-1;++i)fac[i]=(ll)fac[i-1]*i%P;
	inv[MN*MN-1]=qp(fac[MN*MN-1],P-2);
	for(int i=MN*MN-1;i>=1;--i)inv[i-1]=(ll)inv[i]*i%P;
	for(int i=1;i<=n;++i){
		f[i][0]=(ll)f[i-1][0]*C(i*m-i-1,m-2)%P;
		for(int j=1;j<=i;++j){
			f[i][j]=((ll)f[i][j-1]+(ll)f[i-1][j]*C(i*m+j-i-1,m-2)%P)%P;
		}
	}
	printf("%lld\n",(ll)f[n][n]*fac[n]%P);
}
int main(){
	input();
	return 0;
}
