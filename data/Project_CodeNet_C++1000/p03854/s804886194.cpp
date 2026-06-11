#include <bits/stdc++.h>
#define M_PI           3.14159265358979323846  /* pi */
using namespace std;
using  ll = long long;

vector<string>A = { "dream", "dreamer", "erase", "eraser" };

int main() {
	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	for (int i = 0; i < 4; i++) {
		reverse(A.at(i).begin(), A.at(i).end());
	}

	bool result = true;

	for (int i = 0; i < s.size(); i++) {
		bool divide = false;
		for (int j = 0; j < 4; j++) {
			string X = A.at(j);

			if (s.substr(i, X.size()) == X) {
				divide = true;
				i += X.size() - 1;
			}
		}
		if (divide == false) {
			result = false;
			break;
		}
	}

	if (result == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}