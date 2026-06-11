#include<bits/stdc++.h>

using namespace std;

int main(){
	string s3;
	cin>>s3;
	string s2=s3;
	string s1=s3;
	for(int i=0;i<s3.size();i++){
		s1[i]=s3[s3.size()-i-1];
	}
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='q'){
			s1[i]='p';
			continue;
		}
		if(s1[i]=='b'){
			s1[i]='d';
			continue;
		}
		if(s1[i]=='p'){
			s1[i]='q';
			continue;
		}
		if(s1[i]=='d'){
			s1[i]='b';
			continue;
		}
	}
	if(s1==s2){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}