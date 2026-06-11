#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
string s;int len;char a[100005],b[100005];
int main()
{
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){a[i]=s[i];b[len-i-1]=s[i];}
	for(int i=0;i<len;i++)
	{
		if(b[i]=='b') b[i]='d';
        else if(b[i]=='d') b[i]='b';
        else if(b[i]=='p') b[i]='q';
        else if(b[i]=='q') b[i]='p';
	}
//	cout<<a<<endl<<b;
	for(int i=0;i<len;i++)if(a[i]!=b[i]){cout<<"No"<<endl;return 0;}
	cout<<"Yes"<<endl;
	return 0;
}
