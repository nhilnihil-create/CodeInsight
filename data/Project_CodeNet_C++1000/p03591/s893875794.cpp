#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string T = "YAKI";
	vector<char>S(11, ' ');
	for (int i = 0; i < 11; i++) {
		cin >> S.at(i);
	}
	for (int i = 0; i < 4; i++) {
		if (S.at(i) != T.at(i)) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}