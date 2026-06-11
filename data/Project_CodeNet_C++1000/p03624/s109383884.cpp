#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	int alph[30] = {};
	for (int i = 0; i < s.size(); ++i) alph[s[i] - 'a']++;

	int i;
	for (i = 0; i < 26; ++i) {
		if (alph[i] == 0) {
			cout << (char)(i + 'a') << endl;
			break;
		}
	}
	if (i == 26) {
		cout << "None" << endl;
	}
}