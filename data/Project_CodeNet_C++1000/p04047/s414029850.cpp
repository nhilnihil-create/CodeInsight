#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
int l[520];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)scanf("%d",&l[i]);
	sort(l+1,l+2*n+1);
	for(int i=2;i<=2*n;i+=2)
	 	ans+=l[i-1];
	printf("%d",ans);
	return 0;
}