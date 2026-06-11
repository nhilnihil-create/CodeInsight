#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,l,t,cnt,ans[100010];
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for(int x,y,i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		ans[i]=x+t*(y==1?1:-1);
		cnt+=ans[i]>0?ans[i]/l:(ans[i]-l+1)/l;
		ans[i]=(ans[i]%l+l)%l;
	}
	sort(ans+1,ans+n+1);
	cnt=(cnt%n+n)%n;
	for(int i=cnt+1;i<=n;i++)
		printf("%d\n",ans[i]);
	for(int i=1;i<=cnt;i++)
		printf("%d\n",ans[i]);
	return 0;
}