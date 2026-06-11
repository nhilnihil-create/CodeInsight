#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int cc=s.length();
	for(int i=0;i<=cc/2;i++)
	{
		if(s[i]=='b'){if(s[cc-i-1]!='d'){cout<<"No";return 0;}}
		if(s[i]=='d'){if(s[cc-i-1]!='b'){cout<<"No";return 0;}}
		if(s[i]=='p'){if(s[cc-i-1]!='q'){cout<<"No";return 0;}}
		if(s[i]=='q'){if(s[cc-i-1]!='p'){cout<<"No";return 0;}}
	}
	cout<<"Yes";
	return 0;
}
