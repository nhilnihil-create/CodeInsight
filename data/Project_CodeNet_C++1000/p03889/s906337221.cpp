#include<bits/stdc++.h>
using namespace std;
string s;
string cs;
int main(){
	cin>>s;
	int slong=s.size();
	for(int i=slong-1;i>=0;i--)
		cs+=s[i];
	for(int i=0;i<slong;i++)
	{
		if(cs[i]=='b') cs[i]='d';
		else if(cs[i]=='d') cs[i]='b';
		else if(cs[i]=='p') cs[i]='q';
		else if(cs[i]=='q') cs[i]='p';
	}
	if(cs==s)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}