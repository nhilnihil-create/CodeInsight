// luogu-judger-enable-o2
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
	cin>>s;
	int len=s.length();
	if (s[0]==s[len-1]){
		if (len&1) puts("Second");
		else puts("First");
	}
	else{
		if (len&1) puts("First");
		else puts("Second");
	}
	return 0;
}