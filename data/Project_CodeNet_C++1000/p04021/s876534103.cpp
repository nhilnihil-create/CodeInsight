#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,x,tot,cnt,sum;
int a[N],b[N],c[N];
int main(){
	scanf("%d",&n);
	for (register int i=1; i<=n; ++i)
	{ 
		scanf("%d",&x);
		if (i&1) a[++tot]=x;
		else b[++cnt]=x;
		c[i]=x;	
	}
	sort(a+1,a+tot+1); sort(b+1,b+cnt+1);
	sort(c+1,c+n+1);
	for (register int i=1; i<=tot; i++) 
	{
		int pos=lower_bound(c+1,c+n+1,a[i])-c;
		if (pos%2!=1) sum++;
	}
	for (register int i=1; i<=cnt; ++i)
	{
		int pos=lower_bound(c+1,c+n+1,b[i])-c;
		if (pos%2!=0) sum++;
	}
	printf("%d\n",sum/2);
return 0;	
}