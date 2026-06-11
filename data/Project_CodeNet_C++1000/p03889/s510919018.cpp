#include <bits/stdc++.h>
#define ll long long 
#define inf 0x3f3f3f3f
using namespace std;
char check(char ch){
	char t;
	if (ch=='q')t='p';
	if (ch=='d')t='b';
	if (ch=='p')t='q';
	if (ch=='b')t='d';
	return t;
}
char s[393939];
signed main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (int i=1;i<=len;++i){
		char ch1=s[i],ch2=s[len-i+1];
		ch2=check(ch2);
		if (ch1!=ch2){puts("No");return 0;}
	}
	puts("Yes");
	return 0;
}