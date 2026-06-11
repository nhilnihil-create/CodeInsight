#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	string s;
	cin>>s;
	int n=s.length();
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{cout<<i+1<<" "<<i+2<<"\n";return 0;}
	}
	for(int i=0;i<n-2;i++)
	{
		if(s[i]==s[i+2]){cout<<i+1<<" "<<i+3<<"\n";return 0;}
	}
	puts("-1 -1");
}
