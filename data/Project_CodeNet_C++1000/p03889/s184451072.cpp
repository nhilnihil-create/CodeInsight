#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
char f2[500];
string st1,st2;
int l;
int main()
{
	cin>>st1;
	f2['b']='d';
	f2['d']='b';
	f2['p']='q';
	f2['q']='p';
	l=st1.size();
	st2=st1;
	reverse(st1.begin(),st1.end());
	for (int i=0;i<l;i++)
		if (st2[i]!=f2[st1[i]])
		{
			cout<<"No";
			return 0;
		}
	cout<<"Yes";
	return 0;
}