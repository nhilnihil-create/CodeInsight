#include<bits/stdc++.h>
using namespace std;

string f,p;
int l,i;
int main()
{
	cin>>f;
	p=f;
	l=f.size();
	for(i=0;i<l;i++)
	{
		p[i]=f[l-i-1];
	}
	for(i=0;i<l;i++)
	{
		if(p[i]=='b')p[i]='d';
		else if(p[i]=='d')p[i]='b';
		else if(p[i]=='p')p[i]='q';
		else if(p[i]=='q')p[i]='p';
	}
	if(p==f)cout<<"Yes"<<endl;
	  else cout<<"No"<<endl;
	return 0;
}