#include<bits/stdc++.h>
using namespace std;
string s;
int len;
bool chk(int a,int b)
{
	if(((s[a]=='d')&&(s[b]=='b'))||((s[a]=='b')&&(s[b]=='d'))||((s[a]=='p')&&(s[b]=='q'))||((s[a]=='q')&&(s[b]=='p')))
		return true;
	return false;
}
int main()
{
	cin>>s;
	len=s.length();
	if(len&1)
	{
		cout<<"No";
		return 0;
	}
	for(int i=0;i<(len/2);i++)
	{
		if(!chk(i,len-i-1))
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;

}