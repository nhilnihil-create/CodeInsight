#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.size();
	if(len%2==1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	//cout<<s<<endl;
	for(int i=0;i<len/2;i++)
	{
		if((s[i]=='p'&&s[len-i-1]=='q')||(s[i]=='q'&&s[len-i-1]=='p')||(s[i]=='d'&&s[len-i-1]=='b')||(s[i]=='b'&&s[len-i-1]=='d'))
		{
			continue;
		}
		else
		{
			cout<<"No"<<endl;
			return 0;
		}
	} 
	cout<<"Yes"<<endl;
	return 0;
}
