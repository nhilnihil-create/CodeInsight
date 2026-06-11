#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;string s,t;
	cin>>n>>s>>t;
	int i=0,prev=0; ll ans=1;
	if(s[0]==t[0])
	{
		ans*=3;
		prev=1;
		i=1;
	}
	else
	{
		ans*=6;
		prev=2;
		i=2;
	}
	for(;i<n;i++)
	{
		if(s[i]==t[i])
		{
			if(prev==1)
				ans = (ans*2LL)%1000000007;

			prev=1;
		}
		else
		{
			if(prev==1){
				ans = (ans*2LL)%1000000007;

			}
			else
				ans = (ans*3L)%1000000007;

			prev=2;
			i++;
		}
		ans =ans % 1000000007;

	}
	cout<<ans<<"\n";
}