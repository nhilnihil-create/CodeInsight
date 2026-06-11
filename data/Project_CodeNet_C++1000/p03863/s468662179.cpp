#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	string s;
	cin>>s;
	cout<<(((s.size()%2)^(s[s.size()-1]==s[0]))?"First":"Second")<<endl;
	return 0;
}