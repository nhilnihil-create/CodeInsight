#include<bits/stdc++.h>
using namespace std;
const int u=100010;
char s[u],a[u];
int main()
{
	int l,i;
	cin>>s;
	l=strlen(s);
	for(i=0;i<l;++i)
	{
		a[l-i-1]=s[i];
		if(a[l-i-1]=='b')
			a[l-i-1]='d';
		else if(a[l-i-1]=='d')
			a[l-i-1]='b';
		else if(a[l-i-1]=='p')
			a[l-i-1]='q';
		else if(a[l-i-1]=='q')
			a[l-i-1]='p';
	}

	if(strcmp(s,a)==0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}