#include<bits/stdc++.h>
using namespace std;
#define RI register int
int a[105],n,ans;
int main()
{
	cin>>n;
	for(RI i=1;i<=n+n;++i) cin>>a[i];
	sort(a+1,a+1+n+n);
	for(RI i=1;i<=n+n;i+=2) ans+=a[i];
	printf("%d\n",ans);
	return 0;
}