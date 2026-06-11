
// -------------------------------------------------------
#include <iostream>
#include <string>
#include <stdio.h>
#include <cassert>
#include <vector>
using namespace std;

int main() {
	int A, B, C;
	// string s;
#ifdef DEBUG
	int a = 5;
	int b = 7;
	int c = 5;
    A = a; B = b; C = c;
#else
	cin >> A >> B >> C;
#endif

	vector<int> vec{ A, B, C };
	// cin >> s;
	vector<int> five;
	vector<int> seven;

	for (int i : vec) {
		if (i == 5) {
			five.push_back(1);
		}
		else if (i == 7) {
			seven.push_back(1);
		}
	}
	if (five.size() == 2 && seven.size() == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

#ifdef DEBUG
	cin >> A;
#endif
	return 0;
}