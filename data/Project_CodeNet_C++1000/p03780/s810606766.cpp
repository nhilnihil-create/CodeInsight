#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int s[5050];
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int num=n,temp,ans=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if(temp>=k) num--;
		else s[ans++]=temp;
	}
	ans--;
	sort(s+1,s+num+1,cmp);
	temp=0;
	while(num>=2)
	{
		temp+=s[num];
		if(s[num-1]+temp<k)
		{
			num--;
			continue;
		}
		if(s[1]+temp>=k)
		{
			ans=0;
			break;
		}
		int l=1,r=num-2;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(temp+s[mid]>=k) r=mid;
			else l=mid;
		}
		ans=ans-(num-r);
		num=r;
	}
	printf("%d\n",ans);
	return 0;
}