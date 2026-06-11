#include<bits/stdc++.h>
using namespace std;
int a[200010],st[200010];
long long num[200010];
int main()
{
	int n,top=0;long long sum=0;scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char ch='+';if (i!=1) scanf(" %c",&ch);
		scanf("%d",&a[i]);
		sum+=a[i];
		if (ch=='-') st[++top]=a[i];else num[top]+=a[i];
	}
	long long ans=(top)?(-1e18):sum;
	for (int i=1;i<=top;i++)
	{
		ans=max(ans,sum-2*(st[i]+num[i]));
		sum-=2*st[i];
	}
	printf("%lld\n",ans);
}