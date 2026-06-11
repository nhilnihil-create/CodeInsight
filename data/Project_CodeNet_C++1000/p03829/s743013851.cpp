#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,a,ans=0,b,o,p;
	cin>>n>>a>>b>>o;
	for(int i=1;i<n;i++)
	{
		cin>>p;
		if((p-o)*a>b)ans+=b;
		else ans+=a*(p-o);
		o=p;
	}
	cout<<ans;
	return 0;
}
