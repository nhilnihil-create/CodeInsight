#include<bits/stdc++.h>
using namespace std;
char a[100100],s1[100100];
int m;
bool mark;
int main(){
	cin>>a;
	m=strlen(a);
	for(int i=0;i<m;i++)
		s1[i]=a[i];
	for(int i=0;i<m;i++){
		if(a[i]=='b')
		a[i]='d';
		else if(a[i]=='d')
		a[i]='b';
		else if(a[i]=='p')
		a[i]='q';
		else if(a[i]=='q')
		a[i]='p';
	}/*
	for(int i=0;i<m;i++)
		cout<<s1[i];
	cout<<endl;
	for(int i=m-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;*/
	mark=1;
	for(int i=0;i<m;i++){
		if(a[i]!=s1[m-i-1])
			mark=0;
	}
	if(mark==0)
	cout<<"No";
	else
	cout<<"Yes";
	return 0;
} 