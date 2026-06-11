#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	string s; cin >> s;
	int left;
	int right;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			left = i;
			break;
		}
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'Z') {
			right = i;
			break;
		}
	}
	cout << right - left + 1 << endl;
	return 0;
}