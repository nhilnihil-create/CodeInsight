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
#define MN 100000
int a[MN+5];
int main()
{
	int n,m,i;
	n=read();m=read();
	for(i=1;i<=m;++i)a[i]=read();
	for(i=2;i<m;++i)if(a[i]&1)
		if(a[1]&1)
			if(a[m]&1)return 0*puts("Impossible");
			else swap(a[i],a[m]);
		else swap(a[1],a[i]);
	for(i=1;i<=m;++i)printf("%d ",a[i]);puts("");
	if(m==1){if(a[1]==1)puts("1\n1");else printf("2\n%d %d",a[1]-1,1);return 0;}
	printf("%d\n",m-(a[1]<2));
	if(a[1]>1)printf("%d ",a[1]-1);
	for(i=2;i<m;++i)printf("%d ",a[i]);printf("%d",a[m]+1);
}