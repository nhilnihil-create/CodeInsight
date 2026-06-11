#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int len=s.length();
	for(int i=len-1;i>=0;i--)
		if((s[i]=='b' && s[len-1-i]=='d')||(s[i]=='d' && s[len-1-i]=='b')||(s[i]=='p' && s[len-1-i]=='q')||(s[i]=='q' && s[len-1-i]=='p'))
			continue;
		else
		{
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}