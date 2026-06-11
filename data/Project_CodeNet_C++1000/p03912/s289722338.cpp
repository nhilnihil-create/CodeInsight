#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dat[100001];
int cnt[100001];
int gen[100001];
int main()
{
	int num,mod;
	scanf("%d%d",&num,&mod);
	for(int i=0;i<num;i++)
	{
		int z;
		scanf("%d",&z);
		cnt[z%mod]++;
		dat[z]++;
	}
	for(int i=0;i<=100000;i++)
	{
		gen[i%mod]+=dat[i]/2;
	}
	int ret=0;
	for(int i=0;i+i<=mod;i++)
	{
		if(i==0||i+i==mod)ret+=cnt[i]/2;
		else
		{
			if(cnt[i]<cnt[mod-i])ret+=cnt[i]+min((cnt[mod-i]-cnt[i])/2,gen[mod-i]);
			else ret+=cnt[mod-i]+min((cnt[i]-cnt[mod-i])/2,gen[i]);
		}
	}
	printf("%d\n",ret);
}
