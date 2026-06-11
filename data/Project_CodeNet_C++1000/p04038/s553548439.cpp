#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */


int n,k;
const int N=2e3+5;
int fac[N*N],ifac[N*N];
inline void init(int n){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
inline int comb(int a,int b){
	if(b>a)return 0;
	return mul(fac[a],mul(ifac[b],ifac[a-b]));
}
int f[N][N];
int main()
{
	cin>>n>>k;
	if(k==1){
		puts("1");
		return 0;
	}
	init(n*k);
	f[0][0]=1;
	for(int j=1;j<=n;j++){
		f[0][j]=mul(f[0][j-1],comb(j*(k-1)-1,k-2));
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			f[i][j]=add(f[i-1][j],mul(f[i][j-1],comb(j*(k-1)+i-1,k-2)));
		}
	}
	printf("%d\n",mul(f[n][n],fac[n]));
	return 0;
}
