#include <iostream>
using namespace std;

int main() {
	string S;
	cin >> S;
	int compass[4] = {};
	for (int i = 0; i < (int)S.size(); i++) {
		if (S.at(i) == 'N') compass[0] = 1;
		if (S.at(i) == 'S') compass[1] = 1;
		if (S.at(i) == 'E') compass[2] = 1;
		if (S.at(i) == 'W') compass[3] = 1;
	}

	int flag = 0;
	if ((compass[0] == compass[1]) && (compass[2] == compass[3])) flag = 1;

	if (flag == 1) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}