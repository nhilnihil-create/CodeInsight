#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int len;
bool flag=true;
string s1,s2;

int main(){
	cin>>s1;
	len=s1.length();
	s2=s1;
	for(int i=0;i<len;i++){
		s2[i]=s1[len-i-1];
		if(s2[i]=='b') s2[i]='d';
		else if(s2[i]=='d') s2[i]='b';
		else if(s2[i]=='p') s2[i]='q';
		else if(s2[i]=='q') s2[i]='p';
	}
	for(int i=0;i<len;i++)
		if(s1[i]!=s2[i]) flag=false;
	if(flag) printf("Yes");
	else printf("No");
	return 0;
}