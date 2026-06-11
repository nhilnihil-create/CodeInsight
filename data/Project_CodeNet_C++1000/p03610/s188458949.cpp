#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> vec((s.size() + 1 ) / 2);
	for (int i = 0; i < s.size(); i += 2) {
		vec.at(i / 2) = s.at(i);
	}
	for (int j = 0; j < (s.size() + 1) / 2; j++) {
		cout << vec.at(j);
	}
}