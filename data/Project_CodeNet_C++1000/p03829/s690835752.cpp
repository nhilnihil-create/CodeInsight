#include<bits/stdc++.h>
using namespace std;
unsigned long long x[100010];
int main()
{
	unsigned long long c,b,s,ans=0;
	cin>>c>>b>>s;
	for(int i=0;i<c;i++)
	{
		cin>>x[i];
	}
	for(int i=0;i<c-1;i++)
	{
		ans+=min((x[i+1]-x[i])*b,s);
	}
	cout<<ans<<endl;
	return 0;
}  