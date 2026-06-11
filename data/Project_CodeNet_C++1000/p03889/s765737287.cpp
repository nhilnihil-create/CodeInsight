#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main(){
	cin>>s1;
	s2=s1;
	reverse(s1.begin(),s1.end());
	for(int i=0;i<s1.length();i++){
		if(s1[i]=='b')s1[i]='d';
		else if(s1[i]=='d')s1[i]='b';
		 if(s1[i]=='p')s1[i]='q';
		else if(s1[i]=='q')s1[i]='p';
	}
	for(int i=0;i<s1.length();i++){
		if(s1[i]!=s2[i]){
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}