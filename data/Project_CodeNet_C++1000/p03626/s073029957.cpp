#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	int n;
	ll ans=1,MOD=1000000007;
	string s,t;
	bool flag;	
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			if(s[i]==t[i])
			{
				ans=3;
				flag=true;
			}
			else
			{
				ans=6;
				flag=false;
				i++;
			}
		}
		else
		{
			if(s[i]==t[i])
			{
				if(flag)ans*=2;
				else ans*=1;
				ans%=MOD;
				flag=true;
			}
			else
			{
				if(flag)ans*=2;
				else ans*=3;
				ans%=MOD;
				flag=false;
				i++;
			}
		}
	}
	cout<<ans%MOD<<endl;
	return 0;
}