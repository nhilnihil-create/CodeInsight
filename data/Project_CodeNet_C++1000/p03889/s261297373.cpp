#include<bits/stdc++.h>
using namespace std;
char a[100000],b[100000];
int main(){
	int l,k=0;
	cin>>a;
	l=strlen(a);
	for(int i=0;i<l;i++)
	{
		b[i]=a[l-i-1];
	}
	for(int i=0;i<l;i++)
	{
		if(b[i]=='b') b[i]='d';
		else if(b[i]=='d') b[i]='b';
		else if(b[i]=='p') b[i]='q';
		else if(b[i]=='q') b[i]='p';
	}
	for(int i=0;i<l;i++)
	{
		if(a[i]==b[i]) k++;
	}
	if(k==l) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}