#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
string s,st;
int main()
{
	cin >>s;
	st="";
	for (int i=s.size()-1; i>=0; i--)
	    st+=s[i];
	for (int i=0; i<st.size(); i++)
	    if (st[i]=='b') st[i]='d';
	       else if (st[i]=='d') st[i]='b';
	       else if (st[i]=='p') st[i]='q';
	       else if (st[i]=='q') st[i]='p';
	if (st==s) cout<<"Yes";
	   else cout<<"No";
	return 0;
}