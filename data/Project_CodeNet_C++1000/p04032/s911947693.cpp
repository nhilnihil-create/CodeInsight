#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	string s;
	cin>>s;
	ll c=s.length();
	int flag=0;
	for(int i=0;i<c-1;i++)
	{
		if(s[i]==s[i+1] ||((s[i]==s[i+2]) && i<c-2))
		{
			if(s[i]==s[i+1])
			{
				cout<<i+1<<" "<<i+2<<endl;
				return(0);
			}
			if(s[i]==s[i+2])
			{
				cout<<i+1<<" "<<i+3<<endl;
				return(0);
			}
		}
	}
	if(flag==0)
	cout<<-1<<" "<<-1<<endl;
}