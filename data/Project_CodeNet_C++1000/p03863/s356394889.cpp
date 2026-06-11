#include<bits/stdc++.h>
using namespace std;
int len;
string s; 
int main(){
	getline(cin,s);
	len=s.size();
	if(s[0]==s[len-1]){
		if(len%2==1){
			cout<<"Second";
		}
		else{
			cout<<"First";
		}
	}
	else{
		if(len%2==1){
			cout<<"First";
		}
		else{
			cout<<"Second";
		}
	}
	return 0;
}