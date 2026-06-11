#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char a[100001],b[100001];

int main() {
	scanf("%s",a);
	int n=strlen(a);
	for(int i=0;i < n;i++) {
		b[i]=a[i];
		if(b[i]=='b') {b[i]='d';continue;}
		if(b[i]=='d') {b[i]='b';continue;}
		if(b[i]=='p') {b[i]='q';continue;}
		if(b[i]=='q') {b[i]='p';continue;}
	}
	//cout<<b;
	for(int i=0,j=n-1;i < n;i++,j--)
		if(a[i]!=b[j]) {cout<<"No\n";return 0;}
	cout<<"Yes\n";
	return 0;
}
