#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.find('9') == string::npos) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
	}
	return 0;
}
