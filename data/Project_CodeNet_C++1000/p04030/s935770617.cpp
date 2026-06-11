#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<char> v;
	for (char c: s) {
		if (c == 'B') {
			if (!v.empty()) v.pop_back();
		} else {
			v.push_back(c);
		}
	}
	for (char c: v) {
		cout << c;
	}
	cout << endl;
	return 0;
}
