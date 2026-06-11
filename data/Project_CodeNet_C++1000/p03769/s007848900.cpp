#include <cstdio>

using namespace std;
typedef long long LL;

const int N=210;
const LL Inf=1e12+10;

LL n;
int app[N];

void Solve()
{
	int p=0,now=0;
	for (int i=40;i>=0;--i) 
		if ((1ll<<i)<=n) { p=i; break; }
	int tot=p*2+2;now=p+1;
	n-=1ll<<p;
	for (int i=p-1;i>=0;--i)
	{
		if ((1ll<<i)<=n)
		{
			n-=1ll<<i;
			app[i]=++now;
			tot+=2;
		}
	}
	printf("%d\n",tot);
	if (app[0]) printf("%d ",app[0]);
	for (int i=1;i<=p;++i)
	{
		printf("%d ",i);
		if (app[i]) printf("%d ",app[i]);
	}
	for (int i=1;i<=p;++i) printf("%d ",i);
	printf("%d %d ",p+1,p+1);
	for (int i=p;i>=0;--i) if (app[i]) printf("%d ",app[i]);
	putchar('\n');
}

int main()
{
	scanf("%lld",&n);
	Solve();
	return 0;
}