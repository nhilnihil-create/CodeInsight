#include<bits/stdc++.h>
using namespace std;
int main () {
	string s, cs;
	cin >> s;
	for (int i=0; i<s.length(); i++) {
		if (s[i] == 'B' && cs.size()>0) {
			cs.erase(cs.size()-1,1);
		} else {
			if (s[i] != 'B') 
				cs += s[i];
		}
	}
	cout << cs;
	return 0;
}