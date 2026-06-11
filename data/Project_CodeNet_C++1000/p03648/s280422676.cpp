#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define  For(i,a,b) for(int i=a,i##E=b;i<=i##E;++i)
#define rFor(i,a,b) for(int i=a,i##E=b;i>=i##E;--i)
using namespace std;
typedef long long LL;
template<typename T>inline T chkmax(T A,T B){return A>B?A:B;}
template<typename T>inline T chkmin(T A,T B){return A<B?A:B;}
template<typename T>inline void read(T &x)
{
	x=0;int _f(0);char ch=getchar();
	while(!isdigit(ch))_f|=(ch=='-'),ch=getchar();
	while( isdigit(ch))x=x*10+ch-'0',ch=getchar();
	x=_f?-x:x;
}
inline void file()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
}
LL a[60],n,k,m;
int main()
{
	n=50;
	read(k);
	For(i,1,50)a[i]=(k/n)+n-1+(k%n?1:0);
	m=n-(k%n?k%n:n);
	while(m--)
	{
		LL Max=0,pos=0;
		For(i,1,n)if(a[i]>Max)Max=a[i],pos=i;
		For(i,1,n)if(i!=pos)a[i]++;
		a[pos]-=n;
	}
	printf("%lld\n",n);
	For(i,1,n)printf("%lld ",a[i]);
	puts("");
	return 0;
}
