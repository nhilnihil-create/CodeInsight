#include<iostream>
#include<cstring>
using namespace std;
char a[100100],b[100010];
int main()
{
	cin>>a;
	int j=0;
	int l=strlen(a);
	for(int i=l-1;i>=0;i--)
	{
		b[j]=a[i];	
		if(b[j]=='p')
		b[j]='q';
		else if(b[j]=='q')
		b[j]='p';
		else if(b[j]=='b')
		b[j]='d';
		else if(b[j]=='d')
		b[j]='b';
		j++;
	}
	if(!strcmp(a,b))
	cout<<"Yes";
	else cout<<"No";
	return 0;
}