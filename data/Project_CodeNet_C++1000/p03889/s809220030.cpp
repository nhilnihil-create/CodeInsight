#include<iostream>
#include<memory.h>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	int l,t;
	string s,r;
	cin>>s;
	r=s;
	l=s.length();
	t=l-1;
	for(int i=0;i<l;i++)
	{
		s[i]=r[t];
		t--;
	}
	for(int i=0;i<l;i++)
	{
		if(s[i]=='b')s[i]='d';
			else if(s[i]=='d')s[i]='b';
				    else if(s[i]=='p')s[i]='q';
						    else if(s[i]=='q')s[i]='p';
	}
	if(s==r)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	return 0;
}