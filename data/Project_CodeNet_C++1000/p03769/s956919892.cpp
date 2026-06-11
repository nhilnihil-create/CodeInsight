#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,k,prt[1005],cnt,num;
long long n;
int main()
{
	scanf("%lld",&n);
	++n;
	for(k=60;!(n>>k&1);--k);
	--k;
	while(k>=0)
	{
		++num;
		for(i=cnt;i>cnt/2;--i)
			prt[i+1]=prt[i];
		prt[cnt/2+1]=num;
		++cnt;
		for(i=cnt;i>=1;--i)
			prt[i+1]=prt[i];
		++cnt;
		prt[1]=num;
		if(n>>k&1)
		{
			for(i=cnt;i>=1;--i)
				prt[i+1]=prt[i];
			++cnt;
			prt[1]=prt[++cnt]=++num;
		}
		--k;
	}
	printf("%d\n",cnt);
	for(i=1;i<=cnt;++i)
		printf("%d ",prt[i]);
	return 0;
}
