#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int main()
{
	string s;
	cin>>s;
	char s1,s2,s3;

	for(int i=0;i<s.size()-1;i++)
	{
		s1=s[i];
		s2=s[i+1];
		if(s1==s2)
		{
			cout<<i+1<<" "<<i+2<<endl;
			return 0;
		}
		if(i+2<s.size())
		{
			s3=s[i+2];
			if(s1==s3)
			{
				cout<<i+1<<" "<<i+3<<endl;
				return 0;
			}
		}
	}
	cout<<"-1"<<" "<<"-1"<<endl;
}