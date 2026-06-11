#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[55];
ll s[55][55];
int num[55];
int cmp(ll A,ll B)
{
	return A>B;
}
void init()
{
	s[1][1]=1;
	s[1][0]=1;
	for(int i=2;i<=50;i++)
	{
		s[i][0]=1;
		s[i][i]=1;
		for(int j=1;j<i;j++)
		{
			s[i][j]=s[i-1][j-1]+s[i-1][j];
		}
	}
}
int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	init();
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	ll sum=0;
	int k=0;
	num[0]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]==a[i-1])
		{
			num[k]++;
		}
		else
		{
			k++;
			num[k]++;	
		}
	}
	ll ans=0;
	for(int i=1;i<=l;i++)
	{
		sum+=a[i];
	}
	printf("%.6lf\n",sum/(double)l);
	if(num[0]>=l)
	{
		for(int i=l;i<=min(num[0],r);i++)
		{
			ans+=s[num[0]][i];
		}
	}
	else
	{
		int nums=0;
		int keys;
		int keys2;
		for(int i=0;i<=k;i++)
		{
			if(nums+num[i]>=l)
			{
				keys=num[i];
				keys2=l-nums;
				break;
			}
			nums+=num[i];
		}
		ans+=s[keys][keys2];
	}
	printf("%lld\n",ans);
	return 0;
}