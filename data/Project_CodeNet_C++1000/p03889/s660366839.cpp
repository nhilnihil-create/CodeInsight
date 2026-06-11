#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	string s,sttd;cin>>s;sttd=s;reverse(s.begin(),s.end());
	for (int i=0;i<s.length();i++){
		if (s[i]=='b') s[i]='d';
		else if (s[i]=='d') s[i]='b';
		else if (s[i]=='p') s[i]='q';
		else if (s[i]=='q') s[i]='p';
	}
	if (sttd==s) puts("Yes");
	else puts("No");
	return 0;
}