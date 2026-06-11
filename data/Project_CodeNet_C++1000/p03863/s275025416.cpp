#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int a=s.length();
	if(s[0]==s[a-1]) {
		if(a%2==0)
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;
	} else {
		if(a%2==0)
			cout<<"Second"<<endl;
		else
			cout<<"First"<<endl;
	}
}