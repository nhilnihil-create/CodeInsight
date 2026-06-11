#include<bits/stdc++.h>
using namespace std;
int n,a[201];
long long ans=0;
int main()
{
	scanf("%d",&n);
	n*=2;
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i+=2)
	  ans+=a[i];
	printf("%lld",ans);
	return 0;
}