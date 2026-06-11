#include<iostream>
using namespace std;

int main() {
	string s; cin >> s;

	int pre, post;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') {
			pre = i;
			break;
		}
	}
	for (int i = s.size() - 1; i > 0; i--) {
		if (s[i] == 'Z') {
			post = i;
			break;
		}
	}
	cout << post - pre+1 << endl;

	return 0;
}