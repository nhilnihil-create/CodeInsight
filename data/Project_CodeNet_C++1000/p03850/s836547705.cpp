#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const long long MAXN=100005,INF=4223372036854775807ll;
long long n;
long long d[MAXN][3];
long long a;
int main()
{
	scanf("%lld",&n);
	char s[100];
	scanf("%lld",&a);
	for(long long i=0;i<=n+1;i++)
	{
		d[i][0]=d[i][1]=d[i][2]=-INF;
	}
	d[1][0]=a;
	for(long long i=2;i<=n;i++)
	{
		scanf("%s",s);
		scanf("%lld",&a);
		if(s[0]=='+')
		{
			d[i][0]=max(d[i-1][0],d[i-1][1])+a;
			d[i][1]=d[i-1][1]-a;
			d[i][2]=d[i-1][2]+a;
		}
		if(s[0]=='-')
		{
			d[i][0]=-INF;
			d[i][1]=max(d[i-1][0],d[i-1][1])-a;
			d[i][2]=max(d[i-1][1],d[i-1][2])+a;
		}
	}
	printf("%lld\n",max(max(d[n][0],d[n][1]),d[n][2]));
}