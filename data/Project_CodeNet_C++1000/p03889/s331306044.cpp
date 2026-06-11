#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main()
{
	cin>>a;
	
	int len=strlen(a);
	for(int i=0;i<len;++i)
	{
		int loc=len-i-1;
		b[loc]=a[i];
		if(b[loc]=='p') b[loc]='q';
		else if(b[loc]=='q') b[loc]='p';
		else if(b[loc]=='b') b[loc]='d';
		else if(b[loc]=='d') b[loc]='b';
	}
	for(int i=0;i<len;++i) 
	if(a[i]!=b[i]) {cout<<"No"<<endl; goto u;}
	cout<<"Yes"<<endl;
	u: ;
	return 0;
}