#include<functional>
#include<algorithm>
#include<iterator>
#include<cstring>
#include<cstdio>
using namespace std;
int o[111111],r[111111],cr;
long long d[111111],x[111111];
bool viz[111111];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&x[i]);
	for(int i=1;i<=n;++i)
		d[i]=x[i+1]-x[i];
	int m;
	long long k;
	scanf("%d%lld",&m,&k);
	for(int i=1;i<=n;++i)o[i]=i;
	for(int i=1;i<=m;++i)
	{
		int a;
		scanf("%d",&a);
		swap(o[a],o[a-1]);
	}
	for(int i=1;i<=n;++i)
		if(!viz[i])
		{
			cr=0;
			int j=i;
			do viz[r[cr++]=j]=1;while((j=o[j])!=i);
			for(j=0;j<cr;++j)
				o[r[j]]=r[(j+k)%cr];
		}
	for(int i=1;i<=n;++i)
		x[i]=d[o[i]];
	for(int i=n;i;--i)
		x[i]=x[i+1]-x[i];
	for(int i=1;i<=n;++i)
		printf("%lld.0\n",x[i]);
	return 0;
}