#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100007];
int main(){
	scanf("%s",s);int l=strlen(s),f=0;
	if(s[0]==s[l-1])f=1;
	puts((l+f)&1?"First":"Second");
	return 0;
}