#include<bits/stdc++.h>
using namespace std;
string s,a;
int main()
{
    cin>>s;
    for(int i=s.size()-1;i>=0;i--)
    {
    	
    	if(s[i]=='b')
    	a=a+'d';
    	if(s[i]=='d')
    	a=a+'b';
    	if(s[i]=='p')
    	a=a+'q';
    	if(s[i]=='q')
    	a=a+'p';
	}
	if(a==s)
	cout<<"Yes";
	else
	cout<<"No";
    return 0;
}
