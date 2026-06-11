#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<4;i++) {
		if(i==0) {
			if(s[i]=='Y') {
				ans++;
			}
		}
		else if(i==1) {
			if(s[i]=='A') {
				ans++;
			}
		}
		else if(i==2) {
			if(s[i]=='K') {
				ans++;
			}
		}
		else {
			if(s[i]=='I') {
				ans++;
			}
		}
	}
	if(ans==4) {
		cout<<"Yes"<<endl;
	}
	else {
		cout<<"No"<<endl;
	}
}
