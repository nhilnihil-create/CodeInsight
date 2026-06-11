#include <bits/stdc++.h>
#define sort stable_sort
using namespace std; 

int _;

int n,k,a[100050],ans;

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	sort(a,a+n);
	for(int i=n-1;i >= n-k;i--)
		ans += a[i];
	printf("%d\n",ans);
	return 0;
}

