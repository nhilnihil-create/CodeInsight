#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, t = "";
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		t += s[i];
		if (t == "erase") {
			if (i + 1 < n && s[i + 1] == 'r') {
				i += 1;
			}
			t = "";
		}
		else if (t == "dream") {
			if (i + 2 < n && s[i + 1] == 'e' && s[i + 2] == 'r') {
				if (i + 3 < n && s[i + 3] == 'a') {
					t = "era";
					i += 3;
				}
				else {
					t = "";
					i += 2;
				}
			}
			else {
				t = "";
			}
		}
	}
	if (t == "") {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}