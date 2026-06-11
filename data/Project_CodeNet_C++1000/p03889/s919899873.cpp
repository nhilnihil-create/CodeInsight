#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	b=a;
	reverse(b.begin(),b.end());
	for (int i=0;i<b.length();i++)
	{
		if (b[i]=='b')b[i]='d';
		else if (b[i]=='d')b[i]='b';
		else if (b[i]=='p')b[i]='q';
		else  if (b[i]=='q')b[i]='p';
	}
	if(a==b)
	{
		cout<<"Yes"<<'\n';
		return 0;
	}
	cout<<"No"<<'\n';
}