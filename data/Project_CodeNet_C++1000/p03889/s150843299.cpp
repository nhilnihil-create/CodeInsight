#include<iostream>
#include<cstring>
using namespace std;
char a[100001],b[100001];
int main()
{
	cin>>a;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		if(a[i]=='p') b[len-i-1]='q';
		if(a[i]=='q') b[len-i-1]='p';
		if(a[i]=='b') b[len-i-1]='d';
		if(a[i]=='d') b[len-i-1]='b';
	}
	//cout<<a<<endl<<b;
	if((strcmp(a,b))==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}