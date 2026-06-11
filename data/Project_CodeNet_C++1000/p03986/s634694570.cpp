#include<iostream>
#include<string.h>
using namespace std;
string s;
void judge(string& s)
{
	for(int i=0;i<s.length()-1&&s.length()>2;i++)
	{
		if(s[i]=='S'&&s[i+1]=='T')
		{
			s.erase(i,2);	
			i=i-2;
			if(i<-1)
			i=-1;
		}
	}
}
int main()
{
	cin>>s;
	int c;
	c=s.size();
	if(c==1)
	{
		cout<<1<<endl;
		return 0;
	}
	else if(c==2)
	{
		if(s[0]=='S'&&s[1]=='T')
		{
			cout<<0<<endl;
			return 0;
		}
		else
		cout<<2<<endl;
		return 0;
	}
	judge(s);
	c=s.size();
	if(c==1)
	{
		cout<<1<<endl;
		return 0;
	}
	else if(c==2)
	{
		if(s[0]=='S'&&s[1]=='T')
		{
			cout<<0<<endl;
			return 0;
		}
		else
		cout<<2<<endl;
		return 0;
	}
	cout<<s.length();
} 