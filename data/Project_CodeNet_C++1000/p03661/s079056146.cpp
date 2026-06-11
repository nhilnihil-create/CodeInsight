#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=2;i<=n;++i)
		a[i]+=a[i-1];
	ans=abs(a[1]-(a[n]-a[1]));
	for (int i=2;i<n;++i)
		ans=min(ans,abs(a[i]-(a[n]-a[i])));
	cout<<ans;
}