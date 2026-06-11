#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;
	for(int i=0;i<n;i++)
	{
		string s_temp=s.substr(i);
		string t_temp=t.substr(0,(int)s_temp.size());
		if(s_temp==t_temp)
		{
			cout<<(2*i)+(s_temp.size());
			return 0;
		}
	}
	cout<<2*n;
	return 0;
}
