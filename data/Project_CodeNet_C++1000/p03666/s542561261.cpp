#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a,b,c,d,i,j,k;
int main()
{
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	--n;
	for(i=0;i<=n;++i)
	{
		if(i<=n-i)
		{
			j=n-i-i;
			if(1ll*i*(c-d)-1ll*j*d<=b-a&&1ll*i*(d-c)-1ll*j*c>=b-a)
			{
				printf("YES");
				return 0;
			}
		}
		else
		{
			j=i-(n-i);
			if(1ll*(n-i)*(c-d)+1ll*j*c<=b-a&&1ll*(n-i)*(d-c)+1ll*j*d>=b-a)
			{
				printf("YES");
				return 0;
			}
		}
	}
	printf("NO");
	return 0;
}
