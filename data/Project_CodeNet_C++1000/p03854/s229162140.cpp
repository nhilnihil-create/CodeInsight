#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main() {
	string a;
	cin >> a;

	vector<string> s{ "dream", "dreamer", "erase", "eraser" };

	reverse(a.begin(), a.end());
	for (int i = 0; i < 4; i++) {
		reverse(s.at(i).begin(), s.at(i).end());
	}

	string n;
	bool b = true;

	for (int i = 0; i < a.size();) {
		bool c = false;
		for (int j = 0; j < 4; j++) {
			n = s.at(j);
			if (a.substr(i, n.size()) == n) {
				i += n.size();
				c = true;
			}
		}
		if (!c) {
			b = false;
			break;
		}
	}

	if (b) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}