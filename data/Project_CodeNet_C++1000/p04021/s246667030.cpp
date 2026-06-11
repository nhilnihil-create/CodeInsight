#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct node
{
	int v,p;
}a[100010];
int cmp(node x,node y)
{
	return x.v<y.v;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].v);
		a[i].p=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
		if((a[i].p&1)!=(i&1))
			++ans;
	ans>>=1;
	printf("%d",ans);
}