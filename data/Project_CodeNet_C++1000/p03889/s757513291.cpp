#include<bits/stdc++.h>
using namespace std;
string a;
string fz(string x)
{
	string a="";
	for(int i=x.size()-1; i>=0; i--)
	a+=x[i];
	return a;
}
string jx(string x)
{
	string a="";
	for(int i=0; i<x.size(); i++)
	{
		if(x[i]=='q')a+='p';
		if(x[i]=='p')a+='q';
		if(x[i]=='d')a+='b';
		if(x[i]=='b')a+='d';
	}
	return a;
}
bool check(string x,string y)
{
	for(int i=0; i<x.size(); i++)
	if(x[i]!=y[i])return 0;
	return 1;
}
int main()
{
	cin>>a;
	string b=fz(a);
	if(check(a,b)){cout<<"Yes";return 0;}
	string c=jx(fz(a));
	if(check(a,c)){cout<<"Yes";return 0;}
	cout<<"No";
	return 0;
}