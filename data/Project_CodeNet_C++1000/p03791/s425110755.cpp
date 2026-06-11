#include<cstdio>
using namespace std;
long long m,v[100001];
long long ans=1,cnt=0,p=0,k=1;
int main()
{
	scanf("%lld",&m);
	for(int i=1;i<=m;i++)
	{
	scanf("%lld",&v[i]);
	int z=(v[i-1]+1)/2-(i-1);
	while(z<p)
	{
		ans=ans*cnt%1000000007;
		cnt--;
		p--;
		k++;
	}
	cnt++;
	}
	for(;k<=m;k++)
	ans=ans*(cnt--)%1000000007;
	printf("%lld",ans);
}