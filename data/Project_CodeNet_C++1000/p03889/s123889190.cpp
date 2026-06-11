#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s,ss;
	cin>>s;
	ss=s;
	int len=s.length();
	for(int i=0;i<len/2;i++)
		swap(s[i],s[len-i-1]);
	for(int i=0;i<len;i++)
		switch(s[i])
		{
			case'b':s[i]='d';break;
			case'd':s[i]='b';break;
			case'p':s[i]='q';break;
			case'q':s[i]='p';break;
		}
	if(ss==s)cout<<"Yes";
		else cout<<"No";
	return 0;
}