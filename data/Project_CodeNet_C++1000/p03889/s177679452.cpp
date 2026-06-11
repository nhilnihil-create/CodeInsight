# include <bits/stdc++.h>
using namespace std;

int main() {
	string s1; cin >> s1;
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	for(int i = 0; i < s2.size(); ++i)
		if(s2[i] == 'b') s2[i] = 'd';
		else if(s2[i] == 'd') s2[i] = 'b';
		else if(s2[i] == 'p') s2[i] = 'q';
		else if(s2[i] == 'q') s2[i] = 'p';
	if(s1 == s2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}