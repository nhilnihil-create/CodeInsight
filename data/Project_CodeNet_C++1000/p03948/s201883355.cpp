#include<bits/stdc++.h>
using namespace std;
int n,t,a[100005],mx[100005],cnt=0,kmp=0;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		//mx[i]=max(mx[i-1],a[i]);
	}
	mx[n]=a[n];
	for(int i=n-1;i>=1;i--)
	{
		mx[i]=max(mx[i+1],a[i]);
	}
	for(int i=1;i<n;i++)
	{
		if(mx[i+1]-a[i]>kmp)
		{
			kmp=mx[i+1]-a[i];
			cnt=1;
		}else if(mx[i+1]-a[i]==kmp)
		{
			++cnt;
		}
	}
	printf("%d\n",min(cnt,kmp/2));
}