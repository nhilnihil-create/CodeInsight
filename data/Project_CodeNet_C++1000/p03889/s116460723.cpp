#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s,a;
	cin>>s;a=s;
	reverse(s.begin(),s.end());
	
	for(int i=0;i<s.length();i++){
		if(s[i]=='b') s[i]='d';
		else if(s[i]=='d') s[i]='b';
		else if(s[i]=='p') s[i]='q';
		else if(s[i]=='q') s[i]='p';
	}
	if(s==a) cout<<"Yes\n";
	else cout<<"No\n";
}