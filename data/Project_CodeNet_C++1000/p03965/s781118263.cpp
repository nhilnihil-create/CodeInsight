#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,t1,t2;
	string s;
	cin>>s;
	t=s.size();
	for(int i=0;i<=t;i++)
	{
		if(s[i]=='p')t1++;
	}
	cout<<s.size()/2-t1;
	return 0;
}