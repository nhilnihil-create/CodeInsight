
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	string o,e;
	cin>>o>>e;
	int n=o.length()+e.length();
	string ans="";
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			ans+=e[i/2];
		}
		else ans+=o[i/2];
	}
		cout<<ans;
	
}