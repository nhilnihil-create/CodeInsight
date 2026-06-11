#include<bits/stdc++.h>
using namespace std;
char s[1000000],s1[1000000];
map<char,char>mp;
int main(){
	gets(s+1);
	mp['b']='d';mp['d']='b';mp['p']='q';mp['q']='p';
	int l=strlen(s+1);
	for(int i=1;i<=l;i++)
	s1[l-i+1]=mp[s[i]];
	if(strcmp(s+1,s1+1)==0)puts("Yes");
	else puts("No");
	return 0;
}