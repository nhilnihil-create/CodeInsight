#include<bits/stdc++.h>
#define ui unsigned int
#define ll long long
#define db double
#define ld long double
#define ull unsigned long long
#define ft first
#define sd second
#define pb(a) push_back(a)
#define mp(a,b) std::make_pair(a,b)
#define ITR(a,b) for(auto a:b)
#define REP(a,b,c) for(register int a=(b),a##end=(c);a<=a##end;++a)
#define DEP(a,b,c) for(register int a=(b),a##end=(c);a>=a##end;--a)
const int MAXN=2000000+10;
int n,A[MAXN],p[MAXN];
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
inline bool check(int las)
{
	REP(i,1,n+n-1)p[i]=(A[i]>=las);
	if(p[n]==p[n-1])return p[n];
	if(p[n]==p[n+1])return p[n];
	REP(i,1,n-1)
	{
		if(p[n-i]==p[n-i+1])return p[n-i+1];
		if(p[n+i]==p[n+i-1])return p[n+i-1];
	}
	return p[n]^((n-1)&1);
}
int main()
{
	read(n);
	REP(i,1,n+n-1)read(A[i]);
	if(n==1)
	{
		printf("%d\n",A[n]);
		return 0;
	}
	int l=1,r=n+n-1,ans=r;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	write(ans,'\n');
	return 0;
}
