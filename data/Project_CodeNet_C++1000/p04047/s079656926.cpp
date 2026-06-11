#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long ans,l[210];
int main()
{
	scanf("%d",&n);
	n*=2;
	for(int i=1;i<=n;i++)
		scanf("%lld",&l[i]);
	sort(l+1,l+1+n);
	for(int i=1;i<n;i+=2)
		ans+=l[i];
	printf("%lld",ans);
}