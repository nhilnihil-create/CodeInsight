#include<bits/stdc++.h>
using namespace std;
string s,s1;
int main()
{
	cin>>s;
	for(int i=s.size()-1;i>=0;i--)s1+=s[i];
	for(int i=0;i<s1.size();i++)if(s1[i]=='b')s1[i]='d';else if(s1[i]=='d')s1[i]='b';else if(s1[i]=='p')s1[i]='q';else s1[i]='p';
	if(s==s1)cout<<"Yes";else cout<<"No";
}