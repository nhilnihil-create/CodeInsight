#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,d[100005];
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d",&i,&j);
		++d[i],++d[j];
	}
	for(i=1;i<=n;++i)
		if(d[i]&1)
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}
