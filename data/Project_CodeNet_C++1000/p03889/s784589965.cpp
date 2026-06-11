#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("1.out","w",stdout);
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
	for (int i=0;i<b.length();i++)
	{
		if (b[i]!=a[i])
		{
			cout<<"No"<<'\n';
			return 0;
		}
	}
	cout<<"Yes"<<'\n';
}