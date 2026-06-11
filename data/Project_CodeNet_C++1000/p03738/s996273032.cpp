#include <bits/stdc++.h>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	if (A.size() < B.size()) {
		cout << "LESS" << endl;
	}
	else if (A.size() > B.size()) {
		cout << "GREATER" << endl;
	}
	else {
		for (int i = 0; i < A.size(); i++) {
			if (A.at(i) == B.at(i) && i < A.size() - 1) {
				continue;
			}
			else if (A.at(i) == B.at(i) && i == A.size() - 1) {
				cout << "EQUAL" << endl;
			}
			else if (A.at(i) < B.at(i)) {
				cout << "LESS" << endl;
				break;
			}
			else {
				cout << "GREATER" << endl;
				break;
			}
		}
	}
}
