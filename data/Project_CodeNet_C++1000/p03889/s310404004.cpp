#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	string t=s;
	for(int i=0;i<t.size()/2;i++)
	{
		char tt=t[i];
		t[i]=t[t.size()-i-1];
		t[t.size()-i-1]=tt;
	}
	for(int i=0;i<t.size();i++)
	{
		if(t[i]=='p')t[i]='q';
		else
		if(t[i]=='q')t[i]='p';
		else
		if(t[i]=='b')t[i]='d';
		else
		if(t[i]=='d')t[i]='b';
	}
	if(t==s)cout<<"Yes";
	else cout<<"No";
	return 0;
} 