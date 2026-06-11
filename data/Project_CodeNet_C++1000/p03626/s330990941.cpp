#include <bits/stdc++.h>
#define N 60
#define MOD 1000000007
using namespace std;
long long ans;
string s1,s2;
int main(){
	int i,j,n;
	cin>>n;
	cin>>s1>>s2;
	if(s1[0]==s2[0])
	{
		ans=3;
	}
	else
	{
		ans=6;
	}
	for(i=1;i<n;i++)
	{
		if(s1[i]==s1[i-1])
		{
			continue;
		}
		if(s1[i]!=s2[i])
		{
			if(s1[i-1]!=s2[i-1])
			{
				ans=(ans*3)%MOD;
			}
			else
			{
				ans=(ans*2)%MOD;
			}
		}
		else
		{
			if(s1[i-1]==s2[i-1])
			{
				ans=(ans*2)%MOD;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}