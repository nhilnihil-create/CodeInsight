#include <cstdio>
#include <cstring>
#include <algorithm>
#define R register
using namespace std;
typedef long long LL;
const int MAXN=100100;
int d[MAXN],pmt[MAXN];

void permute(int a[],int b[],int n)
{
	int t[MAXN];
	for(R int i=1;i<=n;++i)
	  t[i]=a[i];
	for(R int i=1;i<=n;++i)
	  a[i]=t[b[i]];
}

void fpow(int a[],LL y,int n)
{
	while(y)
	{
		if(y&1)permute(d,a,n);
		permute(a,a,n),y>>=1;
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	LL l;
	int t1,t2;
	scanf("%lld",&l);
	t1=l;
	for(R int i=2;i<=n;++i)
	{
		scanf("%d",&t2);
		d[i]=t2-t1;
		t1=t2;
	}
	for(R int i=1;i<=n;++i)
	  pmt[i]=i;
	int m;
	LL k;
	scanf("%d%lld",&m,&k);
	for(R int i=1;i<=m;++i)
	{
		scanf("%d",&t1);
		swap(pmt[t1],pmt[t1+1]);
	}
	fpow(pmt,k,n);
	for(R int i=1;i<=n;++i)
	{
		l+=d[i];
		printf("%lld\n",l);
	}
	return 0;
}