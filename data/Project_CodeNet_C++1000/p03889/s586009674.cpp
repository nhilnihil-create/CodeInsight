#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[100005],b[100005];
bool flag=false;
int main()
{
	cin>>a;
	//for(int i=0;i<strlen(a);i++)
	  //b[i]=a[strlen(a)-i-1];
	for(int i=0;i<strlen(a);i++){
		b[i]=a[strlen(a)-i-1];
		if(b[i]=='b') b[i]='d';
		else if(b[i]=='d') b[i]='b';
		else if(b[i]=='p') b[i]='q';
		else if(b[i]=='q') b[i]='p';
	}
	for(int i=0;i<strlen(a);i++)
		if(a[i]!=b[i]) 
		  flag=true;
	if(flag==false) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}