#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const* argv[]) {
	string S;
	cin >> S;
	vector<string> key = {
			"dreamer",
			"dream",
			"eraser",
			"erase",
		};
	reverse(S.begin(), S.end());
	while (S.length() > 0) {
		bool stringFlag = false;
		for (int i = 0; i < key.size(); i++) {
			bool charFlag = true;
			// cout << "***" << key[i] << endl;
			for (int j = key[i].length() - 1; j >= 0; j--) {
				// cout << S[key[i].length() - j - 1] << " " << key[i][j] << endl;
				if (S[key[i].length() - j - 1] != key[i][j]) {
					charFlag = false;
					break;
				}
			}
			if (charFlag) {
				S = S.substr(key[i].length());
				stringFlag = true;
				break;
			}
		}
		if (!stringFlag) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
