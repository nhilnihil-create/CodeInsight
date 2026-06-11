#include<bits/stdc++.h>
using namespace std;

string s,t;

int main(){
	cin>>s;
	t=s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]=='b') s[i]='d';
		else if(s[i]=='d') s[i]='b';
		else if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	}
	if(s==t) printf("Yes");
	else  printf("No");
}