// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
string a,b;
int main(){
	cin>>a;
	b=a;
	reverse(a.begin(),a.end());
	for (register int i=0;i<a.length();++i){
		if (a[i]=='b') a[i]='d';
		else if(a[i]=='d') a[i]='b';
		if(a[i]=='p') a[i]='q';
		else if(a[i]=='q') a[i]='p';
	}
	if (a==b) puts("Yes");
	else puts("No");
	return 0;
}