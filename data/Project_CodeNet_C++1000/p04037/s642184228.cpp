#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int n,a[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",a+i);
	sort(a,a+n);
	reverse(a,a+n);
	for(int i=1;i<=n;++i)
		if(a[i]<=i)
		{
			int k=0;
			while(a[i+k]==i)++k;
			puts((k&1||a[i-1]-(i)&1)?"First":"Second");
			return 0;
		}
}