#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	string words[4] = { "dream", "dreamer", "erase", "eraser" };

	reverse(S.begin(), S.end());
	for (int i = 0; i < 4; i++) {
		reverse(words[i].begin(), words[i].end());
	}

	for (int i = 0; i < S.size();) {
		bool flag = false;
		for (int j = 0; j < 4; j++) {
			string w = words[j];
			if (S.substr(i, w.size()) == w) {
				flag = true;
				i += w.size();
				break;
			}
		}
		if (!flag) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}