#include <bits/stdc++.h>
using namespace std;

string s,r;

int main() {
	cin>>s;
	r=s;
	long long len=s.length();
	//cout<<len<<endl;
	for(long long i=0;i<len;i++) {
		r[i+1]=s[len-i-1];
	}
	for(long long i=len;i>=1;i--) {
		s[i]=s[i-1];
	}
	
	/*
	for(int i=1;i<=len;i++) {
		cout<<r[i]<<" ";
	} 
	cout<<endl;
	for(int i=1;i<=len;i++) {
		cout<<s[i]<<" ";
	}
	cout<<endl;
	*/
	for(long long i=1;i<=len;i++) {
		if(r[i]=='b') r[i]='d';
		else if(r[i]=='d') r[i]='b';
		else if(r[i]=='p') r[i]='q';
		else r[i]='p';
	}
	for(long long i=1;i<=len;i++) {
		//cout<<r[i]<<" "<<s[i]<<endl;
		if(r[i]!=s[i]) {
			cout<<"No"<<endl;
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}