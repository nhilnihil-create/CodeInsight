#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
string s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int ans=0;
	s="CODEFESTIVAL2016";
	cin>>t;
	for(int i=0;i<16;i++)
	if(s[i]!=t[i])ans++;
	cout<<ans<<"\n"; 
	return 0;
} 