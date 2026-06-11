#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+10;
int n,t,a[N],mn,dis,ans;
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
	}
	mn=a[1];
	for(int i=2;i<=n;++i)
	{
		if(mn<a[i])dis=max(dis,a[i]-mn);
		mn=min(mn,a[i]);
	}
	mn=a[1];
	for(int i=2;i<=n;++i)
	{
		if(mn<a[i]&&a[i]-mn==dis)ans++;
		mn=min(mn,a[i]);
	}
	printf("%d\n",ans);
	return 0;
}