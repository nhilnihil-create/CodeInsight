#include <bits/stdc++.h>
using namespace std;
string trange1(string s){
	string t;
	for(int i=s.size()-1;i>=0;i--) t+=s[i];
	return t;
}
string trange2(string s){
	string t;
	for(int i=0;i<s.size();i++){
		if(s[i]=='b') t+='d';
		else if(s[i]=='d') t+='b';
		else if(s[i]=='p') t+='q';
		else t+='p';
	}
	return t;
}
string s,t;
int main(){
    cin>>s;
    t=s;
    s=trange1(s);
    s=trange2(s);
    if(t==s) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
}