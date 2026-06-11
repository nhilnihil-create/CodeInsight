#include <bits/stdc++.h>
using namespace std;

int main(void) {

	string s;
	cin >> s;

	vector <long long> v(26, 0);

	for (int i=0; i<s.size(); i++) {
		long long loc = s.at(i) - 'a';
		v.at(loc)++;
	}

	for (int i=0; i<26; i++) {
		if (!v.at(i)) {
			char c = 'a' + i;
			cout << c << endl;
			break;
		}
		if (i==25) cout << "None" << endl;
	}

}
