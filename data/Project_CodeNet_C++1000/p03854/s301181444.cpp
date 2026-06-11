#include <iostream>
#include <string>

using namespace std;

string divide[4] = { "dream", "dreamer", "erase", "eraser" };

int main(void) {
	string s;
	cin >> s;

	reverse(s.begin(), s.end());
	for (int i = 0; i < 4; i++) {
		reverse(divide[i].begin(), divide[i].end());
	}

	bool can = true;

	for (auto i = 0; i < s.size();) {
		bool can2 = false;
		for (int j = 0; j < 4; j++) {
			string d = divide[j];
			if (s.substr(i, d.size()) == d) {
				can2 = true;
				i += d.size();
				break;
			}
		}
		if (!can2) {
			can = false;
			break;
		}
	}

	if (can) cout << "YES";
	else cout << "NO";

	return 0;
}