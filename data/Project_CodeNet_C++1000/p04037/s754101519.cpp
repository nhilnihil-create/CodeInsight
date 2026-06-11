#include <bits/stdc++.h>
#define il inline
const int N=1e5+5;

int n,a[N];

il bool cmp(int x,int y){return x>y;}

int main()
{
	scanf("%d",&n); int i,j;
	for (i=1; i<=n; i++) scanf("%d",a+i);
	std::sort(a+1,a+n+1,cmp);
	
	for (i=1; i<=n; i++) if (i+1>a[i+1])
	{
		for (j=0; a[i+j+1]==i; j++);
		if ((j&1)||(a[i]-i&1)) puts("First");
		else puts("Second");
		break;
    }
	
	return 0;
}