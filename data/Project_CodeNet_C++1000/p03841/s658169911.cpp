#include <bits/stdc++.h>
using namespace std;

int n,x[505],y[505],a[250010],cnt[505];

bool cmp(int a,int b){return x[a]<x[b];}

void work()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++)  scanf("%d",&x[i]),a[x[i]]=i,cnt[i]=i-1,y[i]=i;
	sort(y+1,y+n+1,cmp);
	for (int i=1,j=1; i<=n*n; i++)
		if (!a[i])
			{
				while ((j<=n)&&(!cnt[y[j]]))  j++;
				if (j<=n)  a[i]=y[j],cnt[y[j]]--;
			}else  if (cnt[a[i]])  puts("No"),exit(0);
	for (int i=1; i<=n; i++)  cnt[i]=n-i;
	for (int i=1,j=1; i<=n*n; i++)
		if (!a[i])
			{
				while ((j<=n)&&(!cnt[y[j]]))  j++;
				if (x[y[j]]<i)  a[i]=y[j],cnt[y[j]]--;
				else  puts("No"),exit(0);
			}
	puts("Yes");
	for (int i=1; i<=n*n; i++)  printf("%d ",a[i]);	
}

int main()
{
	work();
	return 0;
}
