#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='b'&&s[len-i-1]=='d') continue;
		if(s[i]=='d'&&s[len-i-1]=='b') continue;
		if(s[i]=='p'&&s[len-i-1]=='q') continue;
		if(s[i]=='q'&&s[len-i-1]=='p') continue;
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
} 