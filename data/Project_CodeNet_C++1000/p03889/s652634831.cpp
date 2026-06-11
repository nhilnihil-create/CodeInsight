#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
string s;

string rev(string ori){
	string ss=ori;
	int j=ori.length()-1;
	for (int i=0;i<s.length();i++){
		ss[i]=ori[j];j--;
	}
	return ss;
}

int main(){
	cin>>s;
	string s2=s;
	string s3=rev(s);
	for (int i=0;i<s.length();i++){
		if(s2[i]=='b') {s2[i]='d';continue;}
		if(s2[i]=='d') {s2[i]='b';continue;}
		if(s2[i]=='p') {s2[i]='q';continue;}
		if(s2[i]=='q') {s2[i]='p';continue;}
	}
	string s4=rev(s2);
	//cout<<s2<<endl<<s3<<endl<<s4<<endl;
	if(s2==s||s3==s||s4==s) cout<<"Yes";
	else cout<<"No";
	return 0;
}