#include<bits/stdc++.h>
using namespace std;
string s;
char t[10000000];
int len;
int main()
{
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='b') t[len-i-1]='d';
		else if(s[i]=='d') t[len-i-1]='b';
		else if(s[i]=='p') t[len-i-1]='q';
		else if(s[i]=='q') t[len-i-1]='p';
	}
//	cout<<endl;
//	cout<<"s="<<s<<endl;
//	cout<<"t="<<t<<endl;
	for(int i=0;i<len;i++)
		if(s[i]!=t[i])
		{
			cout<<"No\n";
			return 0;
		}
	cout<<"Yes\n";
	return 0;
}