#include<bits/stdc++.h>
using namespace std;
long long n,a,b,s[10000000],ans=0;
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;++i)
		cin>>s[i];
	for(int i=2;i<=n;++i)
	{
		ans+=min(a*(s[i]-s[i-1]),b);
	}
	cout<<ans;
}