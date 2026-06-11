#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define MAXN 100000
using namespace std;
typedef long long LL;
vector<int> vec;
LL sum[MAXN+5],sum2[MAXN+5],a[MAXN+5];
int n;
bool dec[MAXN+5];
char str[5];
int main()
{
	scanf("%d",&n);
	scanf("%lld",&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%s %lld",str,&a[i]);
		if(str[0]=='-')
			vec.push_back(i),dec[i]=true;
	}
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
		if(dec[i]==true)
			sum2[i]=sum2[i-1]-a[i];
		else
			sum2[i]=sum2[i-1]+a[i];
	LL ans=sum2[n];
	int pos1,pos2;
	for(int i=0;i<(int)vec.size()-1;i++)
	{
		pos1=vec[i],pos2=vec[i+1];
		ans=max(ans,sum2[pos1]-(sum[pos2-1]-sum[pos1])+(sum[n]-sum[pos2-1]));
	}
	printf("%lld\n",ans);
	return 0;
}