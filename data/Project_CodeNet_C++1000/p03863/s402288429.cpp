#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s[0] == s[s.size()-1]) {
		if(s.size()%2) puts("Second");
		else puts("First");
	}
	else {
		if(s.size()%2) puts("First");
		else puts("Second");
	}
	return 0;
}