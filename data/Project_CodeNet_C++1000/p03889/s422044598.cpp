#include<iostream>
using namespace std;
string n,s;
int main()
{
	cin>>n;
	s=n;
	for(int i=0;i<n.size();i++)
	 n[n.size()-i-1]=s[i];
	for(int i=0;i<n.size();i++)
	{
		if(n[i]=='b') n[i]='d';
		else if(n[i]=='d') n[i]='b';
		else if(n[i]=='p') n[i]='q';
		else if(n[i]=='q') n[i]='p';
	}
	if(s==n)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}