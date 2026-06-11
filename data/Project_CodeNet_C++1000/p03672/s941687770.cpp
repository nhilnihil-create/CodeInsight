#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
cin>>s;
s.erase(s.length()-1,1);
for(int i=s.length()-1;i>1;i--) {
	if(s.substr(0,(s.length()/2))==s.substr((s.length()/2),(s.length()/2))) {
		cout<<s.length()-1<<endl;
		break;
	} else {
		s.erase(s.length()-1,1);
	}
}
}
