#include <bits/stdc++.h>
using namespace std;
string s,ss;
int main(){
	int i,j,k;
	getline(cin,s);
	ss=s;
	reverse(s.begin(),s.end());
	for(i=0;i<s.length();i++){
		if(s[i]=='b') s[i]='d';
        else if(s[i]=='d') s[i]='b';
        else if(s[i]=='p') s[i]='q';
        else if(s[i]=='q') s[i]='p';
	}
	if(s==ss){
		cout<<"Yes\n";
		return 0;
	}
	cout<<"No\n";
	return 0;
}