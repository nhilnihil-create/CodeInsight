#include <bits/stdc++.h>
using namespace std;

int n,pos;
string S1,S2;

int main()
{
	cin>>n>>S1>>S2;
	long long ans;
	bool v;
	if(S1[0]==S2[0])
	{
		ans=3;
		pos++;
		v=true;
	}
	else
	{
		ans=6;
		pos+=2;
		v=false;
	}
	while(pos<n)
	{
		if(S1[pos]==S2[pos])
		{
			if(v)
				ans*=2;
			pos++;
			v=true;
		}
		else
		{
			if(v)
				ans*=2;
			else 
				ans*=3;
			pos+=2;
			v=false;
		}
		if(ans>=1000000007)
			ans%=1000000007;
	}
	cout << ans << endl;
	return 0;
}
