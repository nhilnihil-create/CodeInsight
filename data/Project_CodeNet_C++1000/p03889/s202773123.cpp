#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	string s1=s;
	int n=s.length();
	if(n%2){cout<<"No";return 0;}
	for(int i=0;i<n/2;++i)
	{		
		if(s1[i]=='b')s1[i]='d';
		else if(s1[i]=='d')s1[i]='b';
		else if(s1[i]=='q')s1[i]='p';
		else if(s1[i]=='p')s1[i]='q';
		if(s1[n-i-1]=='b')s1[n-i-1]='d';
		else if(s1[n-i-1]=='d')s1[n-i-1]='b';
		else if(s1[n-i-1]=='q')s1[n-i-1]='p';
		else if(s1[n-i-1]=='p')s1[n-i-1]='q';
		char t=s1[i];s1[i]=s1[n-i-1];s1[n-i-1]=t;
	}
//	cout<<s1<<endl<<s;
	if(s1==s)cout<<"Yes";
	else cout<<"No";
	return 0;
}
