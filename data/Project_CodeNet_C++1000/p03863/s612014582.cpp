#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool bo[100];
#define ll long long int
int main()
{
	string s;
	cin>>s;
	ll l=(int)s.size();
	if(s[0]==s[l-1])
	{
		if(l%2==0)
		{
			cout<<"First"<<endl;
		}
		else
		{
			cout<<"Second"<<endl;
		}
	}
	else
	{
		if(l%2!=0)
		{
			cout<<"First"<<endl;
		}
		else
		{
			cout<<"Second"<<endl;
		}
	}
}
