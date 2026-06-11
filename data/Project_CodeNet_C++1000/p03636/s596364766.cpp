#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main(){
	char a[1000001];
	gets(a);
	cout<<a[0]<<strlen(a)-2<<a[strlen(a)-1];
	return 0;
} 