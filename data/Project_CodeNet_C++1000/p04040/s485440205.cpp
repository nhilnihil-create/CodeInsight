#include<bits/stdc++.h>
const int MN=200000+5;
const int P=1000000007;
using namespace std;
typedef long long ll;
template<typename T>T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	in*=f;return in;
}
int n,m,a,b,N;ll ans;
ll fac[MN],inv[MN];
ll qp(ll a,ll b){ll c=1;for(;b;b>>=1,a=a*a%P)if(b&1)c=c*a%P;return c;}
ll C(int n,int m){return n>=m?fac[n]*inv[m]%P*inv[n-m]%P:0;}
void input(){
	IN(n),IN(m),IN(a),IN(b),fac[0]=1;N=200000;
	for(int i=1;i<=N;++i)fac[i]=fac[i-1]*i%P;
	inv[N]=qp(fac[N],P-2);
	for(int i=N;i>=1;--i)inv[i-1]=inv[i]*i%P;
	for(int i=b+1;i<=m;++i){
		ans=(ans+C(n-a-1+i-1,i-1)*C(a-1+m-i,a-1)%P)%P;
	}
	printf("%lld\n",ans);
}
int main(){
	input();
	return 0;
}