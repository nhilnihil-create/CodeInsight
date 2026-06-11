#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int i,n,a=0,b=0;
	n=s.size();
	for(i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			a=i;
			break;
		}
	}
	for(i=n-1;i>=0;i--)
	{
		if(s[i]=='Z')
		{
			b=i;
			
			break;
		}
	}
	b=b-a+1;
	cout<<b<<endl;
}