#include<iostream>
using namespace std;
int main()
{
	string s,s1;
	cin>>s;
	s1="CODEFESTIVAL2016";
	int t=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=s1[i])
		{
			t++;
		}
	}
	cout<<t<<endl;
	return 0;
} 