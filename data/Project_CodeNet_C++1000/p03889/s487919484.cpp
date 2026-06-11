#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int i,n,j,k,m,l,o,p;
string s,a;
int main()
{
	cin>>s;
	a=s;
	for(i=0,j=a.length()-1;i<=j;i++,j--)
	{
	swap(a[i],a[j]);
	}
	for(i=0;i<s.length();i++)
	{
	if(a[i]=='d') a[i]='b';
		else if(a[i]=='b') a[i]='d';
			else if(a[i]=='p') a[i]='q';
				else if(a[i]=='q') a[i]='p';
	}
	if(a==s) cout<<"Yes";
		else cout<<"No";
	return 0;
}