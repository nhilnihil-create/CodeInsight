#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
char s[1010100];
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	int N=0,S=0,W=0,E=0;
	for(rint i=1;i<=len;++i) {
		if(s[i]=='S') S=1;
		if(s[i]=='N') N=1;
		if(s[i]=='W') W=1;
		if(s[i]=='E') E=1;
	}
	if(N!=S||W!=E) {
		cout<<"No";
	}else cout<<"Yes";
	return 0;
} 