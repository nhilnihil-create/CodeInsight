#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s,s1;
	cin>>s;
	s1=s;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='b')s1[i]='d';
		else if(s1[i]=='d')s1[i]='b';
		else if(s1[i]=='p')s1[i]='q';
		else if(s1[i]=='q')s1[i]='p';
	}
	if(s1==s)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}