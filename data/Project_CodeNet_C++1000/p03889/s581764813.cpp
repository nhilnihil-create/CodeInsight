#include <bits/stdc++.h>
using namespace std;
int len;
string s,s1,s2;
int main() {
	cin>>s;len=s.length();
	for(int i=len-1;i>=0;i--)s1=s1+s[i];
	for(int i=0;i<len;i++){
		if(s1[i]=='b')s2=s2+'d';
		if(s1[i]=='d')s2=s2+'b';
		if(s1[i]=='p')s2=s2+'q';
		if(s1[i]=='q')s2=s2+'p';
	}
	if(s==s2)printf("Yes\n");
	else printf("No\n");
	return 0;
}
