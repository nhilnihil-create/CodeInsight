#include<bits/stdc++.h>
#define ui unsigned int
#define ll long long
#define db double
#define ld long double
#define ull unsigned long long
#define ft first
#define sd second
#define pb(a) push_back(a)
#define PII std::pair<int,int>
#define PLL std::pair<ll,ll>
#define mp(a,b) std::make_pair(a,b)
#define ITR(a,b) for(auto a:b)
#define REP(a,b,c) for(register int a=(b),a##end=(c);a<=a##end;++a)
#define DEP(a,b,c) for(register int a=(b),a##end=(c);a>=a##end;--a)
const int MAXN=2000+10,MAXM=5000000+10,Mod=1e9+7;
int n,k;
ll f[MAXN][MAXN],fac[MAXM],inv[MAXM];
template<typename T> inline void read(T &x)
{
	T data=0,w=1;
	char ch=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(ch>='0'&&ch<='9')data=((T)data<<3)+((T)data<<1)+(ch^'0'),ch=getchar();
	x=data*w;
}
template<typename T> inline void write(T x,char ch='\0')
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
	if(ch!='\0')putchar(ch);
}
template<typename T> inline bool chkmin(T &x,T y){return y<x?(x=y,true):false;}
template<typename T> inline bool chkmax(T &x,T y){return y>x?(x=y,true):false;}
template<typename T> inline T min(T x,T y){return x<y?x:y;}
template<typename T> inline T max(T x,T y){return x>y?x:y;}
inline ll qexp(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	return res;
}
inline void init(int LM)
{
	fac[0]=1;
	REP(i,1,LM)fac[i]=1ll*fac[i-1]*i%Mod;
	inv[LM]=qexp(fac[LM],Mod-2);
	DEP(i,LM-1,0)inv[i]=1ll*inv[i+1]*(i+1)%Mod;
}
inline ll C(int n,int m)
{
	return 1ll*fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main()
{
	read(n);read(k);init((n+1)*k);
	if(k==1)
	{
		puts("1");
		return 0;
	}
	f[0][0]=1;
	REP(i,0,n)REP(j,0,i)if(i||j)
		f[i][j]=((j?f[i][j-1]:0)+(i?1ll*C((i-1)*(k-1)+j+k-2,k-2)*f[i-1][j]%Mod:0))%Mod;
	write(1ll*f[n][n]*fac[n]%Mod,'\n');
	return 0;
}
