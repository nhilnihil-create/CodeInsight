/*
@Date    : 2019-08-20 10:13:37
@Author  : Adscn (adscn@qq.com)
@Link    : https://www.cnblogs.com/LLCSBlog
*/
#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define RG register
#define gi getint()
#define gc getchar()
#define File(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
IL int getint()
{
	RG int xi=0;
	RG char ch=gc;
	bool f=0;
	while(ch<'0'||ch>'9')ch=='-'?f=1:f,ch=gc;
	while(ch>='0'&&ch<='9')xi=(xi<<1)+(xi<<3)+ch-48,ch=gc;
	return f?-xi:xi;
}
template<typename T>
IL void pi(T k,char ch=0)
{
	if(k<0)k=-k,putchar('-');
	if(k>=10)pi(k/10,0);
	putchar(k%10+'0');
	if(ch)putchar(ch);
}
#define int long long
const int N=2000+7;
const int mod=1e9+7;
inline void exgcd(int a,int b,int &x,int &y)
{
	if(!b){
		x=1,y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=a/b*x;
}
inline int inv(int qwq){
	int x,y;
	exgcd(qwq,mod,x,y);
	return (x%mod+mod)%mod;
}
long long invf[N*N],fac[N*N];
long long f[N][N];
inline int C(int n,int m){
//	if(n>m)return 0;
	return (1ll*fac[m]*invf[n]%mod*invf[m-n])%mod;
}
signed main(void)
{
	#ifndef ONLINE_JUDGE
//	File("");
	#endif
	int n=gi,k=gi;
	if(k==1)return pi(1),0;
	fac[0]=1;
	for(int i=1;i<=N*N;++i)fac[i]=(1ll*fac[i-1]*i)%mod;
	invf[N*N]=inv(fac[N*N]);
	for(int i=N*N-1;~i;--i)invf[i]=(1ll*invf[i+1]*(i+1))%mod;
	f[0][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<=i;++j)
		{
			f[i][j]=f[i-1][j];
			if(j)(f[i][j]+=f[i][j-1]*(n-j+1)%mod*C(k-2,n-i+(n-j+1)*(k-1)-1)%mod)%=mod;
		}
	cout<<f[n][n];
	return 0;
}