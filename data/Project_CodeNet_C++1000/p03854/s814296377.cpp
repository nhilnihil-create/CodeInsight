#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s[4] = { "dream", "dreamer", "erase", "eraser" };

int main() {
	string a;
	cin >> a;

	

	reverse(a.begin(), a.end());
	for (int i = 0; i < 4; ++i) {
		reverse(s[i].begin(), s[i].end());
	}


	bool flag = true;

	for (int i = 0; i < a.size();) {
		bool flag2 = false;
		for (int j = 0; j < 4; ++j) {
			string b = s[j];
			
			if (a.substr(i, b.size()) == b) {
				flag2 = true;
				i += b.size();
			}
		}
		if (!flag2) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}