#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char a[100000],b[100000];
	bool c=true;
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;i++)
		b[l-1-i]=a[i];
	for(int i=0;i<l;i++)
	{
		if(b[i]=='b') b[i]='d';
		else if(b[i]=='d') b[i]='b';
		else if(b[i]=='q') b[i]='p';
		else if(b[i]=='p') b[i]='q';
	}
	for(int i=0;i<l;i++)
		if(a[i]!=b[i])
		{
			c=false;
			break;
		}
	if(c==true) cout<<"Yes";
	else cout<<"No";
	return 0;		
}