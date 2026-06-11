#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int _=2005;
const int mod=1e9+7;
inline int read()
{
	char ch='!';int z=1,num=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')z=-1,ch=getchar();
	while(ch<='9'&&ch>='0')num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return z*num;
}
int n,k,f[_][_];
void add(int &a,int b){a+=b;if(a>=mod)a-=mod;}
const int N=2000*2000;
int jc[N+5],inv[N+5];
int ksm(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)r=1ll*r*a%mod;return r;}
void Pre(){inv[0]=jc[0]=1;for(int i=1;i<=N;++i)jc[i]=1ll*jc[i-1]*i%mod,inv[i]=ksm(jc[i],mod-2);}
int C(int A,int B)
{
	if(A<B)return 0;
	return 1ll*jc[A]*inv[B]%mod*inv[A-B]%mod;
}
int main()
{
	Pre();
	n=read(),k=read();
	if(k==1)return puts("1"),0;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
		{
			add(f[i][j],f[i-1][j]);
			if(j)add(f[i][j],1ll*f[i][j-1]*C(n-i+(n-j+1)*(k-1)-1,k-2)%mod*(n-j+1)%mod);
		}
	printf("%d\n",f[n][n]);
	return 0;
}