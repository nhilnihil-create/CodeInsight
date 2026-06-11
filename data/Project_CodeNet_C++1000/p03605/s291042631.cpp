#include<iostream>

using namespace std;

int main() {
	string N;
	cin >> N;

	bool flagNine = false;
	for (int i = 0; i < N.length(); i++) {
		if (N[i] == '9') {
			flagNine = true;
		}
	}

	if (flagNine) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}