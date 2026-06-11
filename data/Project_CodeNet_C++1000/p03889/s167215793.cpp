#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[100010],b[100010];
string a1,b1;

int main()
{
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++) b[i]=a[len-i-1];
	for(int i=0;i<len;i++)
	{
		if(b[i]=='b') b[i]='d';
		else if(b[i]=='d') b[i]='b';
		else if(b[i]=='q') b[i]='p';
		else b[i]='q';
	}
	a1=a;b1=b;
	if(a1==b1) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}