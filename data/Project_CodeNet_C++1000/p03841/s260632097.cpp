#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500
struct P{int z,k;}p[MN+5];
bool cmp(const P&a,const P&b){return a.k<b.k;}
int s1[MN+5],s2[MN+5],x[MN*MN+5];
int main()
{
	int n=read(),i,j,k;
	for(i=1;i<=n;++i)p[i].z=i,x[p[i].k=read()]=i,s1[i]=i-1,s2[i]=n-i;
	sort(p+1,p+n+1,cmp);
	for(i=j=k=1;i<=n*n;++i)if(!x[i])
	{
		while(j<=n&&!s1[p[j].z])++j;
		if(j<=n){if(i>p[j].k)return 0*puts("No");--s1[x[i]=p[j].z];continue;}
		while(!s2[p[k].z])++k;
		if(i<p[k].k)return 0*puts("No");--s2[x[i]=p[k].z];
	}
	puts("Yes");
	for(i=1;i<=n*n;++i)printf("%d ",x[i]);
}