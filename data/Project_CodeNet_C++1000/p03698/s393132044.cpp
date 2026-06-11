#include <bits/stdc++.h>
using namespace std;
string s;
int temp;
bool valid;
int main() {
cin>>s;
for(int i=1;i<s.length();i++) {
	for(int j=0;j<s.length()-i;j++) {
		if(s[j]>s[j+1]) {
			temp=s[j];
			s[j]=s[j+1];
			s[j+1]=temp;
		}
	}
}
valid=true;
for(int i=0;i<s.length()-1;i++) {
	if(s[i]==s[i+1]) {
		valid=false;
	}
}
if(valid) {
	cout<<"yes"<<endl;
} else {
	cout<<"no"<<endl;
}
}
