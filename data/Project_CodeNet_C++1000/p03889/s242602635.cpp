#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
string s;
int main(){
	getline(cin,s);
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='p'&&s[n-i-1]=='q') continue;
		if(s[i]=='q'&&s[n-i-1]=='p') continue;
		if(s[i]=='b'&&s[n-i-1]=='d') continue;
		if(s[i]=='d'&&s[n-i-1]=='b') continue;
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
} 