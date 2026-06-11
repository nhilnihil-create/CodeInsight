#include <bits/stdc++.h>
using namespace std;
string s;
int l;
int main(){
	cin>>s;
	l=s.length();
	if(s[0]==s[l-1]){
		if((l-2)%2==0)cout<<"First\n";
		else cout<<"Second\n";
	}
	else{
		if((l-2)%2==1)cout<<"First\n";
		else cout<<"Second\n";
	}
}