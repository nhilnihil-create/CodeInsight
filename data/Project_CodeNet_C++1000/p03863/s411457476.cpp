#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	if(s[0]==s[s.size()-1]) {
		if(s.size()%2==0) {
			cout<<"First"<<endl;
		} else {
			cout<<"Second"<<endl;
		}
	}
	if(s[0]!=s[s.size()-1]) {
		if(s.size()%2==1) {
			cout<<"First"<<endl;
		} else {
			cout<<"Second"<<endl;
		}
	}
	return 0;
}