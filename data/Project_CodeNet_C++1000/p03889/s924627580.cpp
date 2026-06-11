#include<iostream>
#include<string> 
using namespace std;
string s,s2;
int main()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]=='b') s2+='d';
		else if(s[i]=='d') s2+='b';
		else if(s[i]=='q') s2+='p';
		else s2+='q';
	}
	if(s2==s) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
/*

*/
