#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string s;
	cin>>s;
	cout<<(((s[0]==s[s.length()-1])^(s.length()%2))?"First\n":"Second\n");
	return 0;
}