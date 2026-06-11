#include<iostream>
#include<cstring>
#define MAX 100000
char a[MAX],b[MAX];
using namespace std;
int main()
{
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;i++) b[l-i-1]=a[i];
	for(int i=0;i<l;i++)
	if(b[i]=='b') b[i]='d';
	else if(b[i]=='d') b[i]='b';
	else if(b[i]=='p') b[i]='q';
	else if(b[i]=='q') b[i]='p';
	for(int i=0;i<l;i++)
	if(a[i]!=b[i])
	{
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}