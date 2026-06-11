#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 100000
long long x[MN+5],ans[MN+5],n,k;
struct data{int p[MN+5];}A,B;
data operator*(const data&x,const data&y)
{
	data res;
	for(int i=1;i<=n;++i)res.p[i]=y.p[x.p[i]];
	return res;
}
int main()
{
	int m,i;
	for(n=read(),i=1;i<=n;++i)x[i]=read(),A.p[i]=B.p[i]=i;
	for(i=n;i;--i)x[i]-=x[i-1];
	m=read();scanf("%lld",&k);
	while(m--)i=read(),swap(B.p[i],B.p[i+1]);
	for(;k;k>>=1,B=B*B)if(k&1)A=A*B;
	for(i=1;i<=n;++i)printf("%lld.0\n",ans[i]=ans[i-1]+x[A.p[i]]);
}