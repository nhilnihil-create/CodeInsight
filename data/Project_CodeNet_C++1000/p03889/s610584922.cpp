#include<bits/stdc++.h>
using namespace std;
char a[100005],b[100005];
int main()
{
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		b[i]=a[strlen(a)-i-1];
		if(b[i]=='b')
		b[i]='d';
		else if(b[i]=='d')
		b[i]='b';
		else if(b[i]=='p')
		b[i]='q';
		else if(b[i]=='q')
		b[i]='p';
		if(b[i]!=a[i]){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}