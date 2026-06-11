#include<bits/stdc++.h>
using namespace std;
int x[510],a[250010],go[250010];
int main()
{
	int n,now=1;scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if (go[x[i]]) {puts("No");return 0;}go[x[i]]=i;
	}
	sort(x+1,x+n+1);
	for (int i=1;i<=n;i++)
	{
		if (a[x[i]]) {puts("No");return 0;}a[x[i]]=i;while (a[now]) now++;
		int w=go[x[i]]-1;
		while (w)
		{
			if (now>x[i]) {puts("No");return 0;}
			a[now]=i;w--;
			now++;while (a[now]) now++;
		}
	}
	now=1;while (a[now]) now++;
	for (int i=1;i<=n;i++)
	{
		now=max(now,x[i]+1);while (a[now]) now++;
		int w=n-go[x[i]];
		while (w)
		{
			if (now>n*n) {puts("No");return 0;}
			a[now]=i;w--;
			now++;while (a[now]) now++;
		}
	}
	puts("Yes");
	for (int i=1;i<=n*n;i++) printf("%d ",go[x[a[i]]]);
}
	
	
	
	
	
	
	
	
	
