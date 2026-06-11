#include<bits/stdc++.h>
using namespace std;
int main () {
	string s;
	cin >> s;
	string ans = "";
	for (int i=0; i<s.length(); i++) {
		if (s[i] =='B') {
			if (ans.size()) ans.pop_back();
		} else 
			ans.push_back(s[i]);
	}
	cout << ans;
	return 0;
}