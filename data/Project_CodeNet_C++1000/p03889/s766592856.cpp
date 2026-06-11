#include<bits/stdc++.h>
using namespace std;
int main() {
	string a;
	cin>>a;
	string b=string(a.rbegin(),a.rend());
	for(int i=0; i<b.length(); i++) {
		if(b[i]=='b')
			b[i]='d';
		else if(b[i]=='d')
			b[i]='b';
		else if(b[i]=='p')
			b[i]='q';
		else if(b[i]=='q')
			b[i]='p';
	}
	if(b==a)
		cout<<"Yes";
	else
		cout<<"No";
}