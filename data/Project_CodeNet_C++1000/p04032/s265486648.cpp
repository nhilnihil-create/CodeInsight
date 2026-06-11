#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for(int i=0; i+1<s.size(); i++)
	{
		if(s[i]==s[i+1])
		{
			cout<<i+1<<" "<<i+2<< endl;
			return 0;
		}
	}
	for(int i=0 ; i+2<s.size(); i++)
	{
		if(s[i]==s[i+2])
		{
			cout<<i+1<<" "<<i+3<< endl;
			return 0;
		}
	}
	
	cout<<"-1"<<' '<<"-1"<< endl;
	return 0;
}
