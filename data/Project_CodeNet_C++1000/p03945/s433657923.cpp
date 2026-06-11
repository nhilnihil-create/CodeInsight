#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main() {
	string S;
	cin >> S;

	int cnt = 1;
	char ch;
	for (int i = 0; i < S.size(); i++) {
		if (!i) {
			ch = S.at(i);
			if (count(S.begin(), S.end(), ch) == S.size()) {
				cout << 0 << endl;
				return 0;
			}
		}
		else {
			if (ch != S.at(i)) {
				cnt++;
				ch = S.at(i);
			}
		}
	}

	cout << cnt - 1 << endl;
}
