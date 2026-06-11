#include <iostream>
#include<string>
using namespace std;
string s,a,b,c;
int r;
int main()
{
	cin>>s;
	a=s;
	b=s;
	c=s;
	for(int q=0;q<a.size();q++)
	   {
	   	if(a[q]=='b')a[q]='d';
	   	if(a[q]=='p')a[q]='q';
	   	if(a[q]=='q')a[q]='p';
	   	if(a[q]=='d')a[q]='b';
	   	b[a.size()-1-q]=s[q];
	   }
	for(int q=0;q<a.size();q++)
	{
		if(b[q]=='b')c[q]='d';
	   	if(b[q]=='p')c[q]='q';
	   	if(b[q]=='q')c[q]='p';
	   	if(b[q]=='d')c[q]='b';
	}
	   if(b==s||a==s||c==s)r=1;
	   if(r==1)cout<<"Yes";
	   if(r==0)cout<<"No";
	return 0;
}
